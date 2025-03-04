#pragma once

#include "common/FlagsEnum.hpp"
#include "messages/Link.hpp"

#include <boost/noncopyable.hpp>
#include <pajlada/signals/signalholder.hpp>
#include <QPen>
#include <QPoint>
#include <QRect>
#include <QString>

#include <climits>
#include <cstdint>

class QPainter;

namespace chatterino {
class MessageElement;
class Image;
using ImagePtr = std::shared_ptr<Image>;
enum class FontStyle : uint8_t;
enum class MessageElementFlag : int64_t;

class MessageLayoutElement : boost::noncopyable
{
public:
    MessageLayoutElement(MessageElement &creator_, const QSize &size);
    virtual ~MessageLayoutElement();

    bool reversedNeutral = false;

    const QRect &getRect() const;
    MessageElement &getCreator() const;
    void setPosition(QPoint point);
    bool hasTrailingSpace() const;
    int getLine() const;
    void setLine(int line);

    MessageLayoutElement *setTrailingSpace(bool value);
    MessageLayoutElement *setLink(const Link &link_);
    MessageLayoutElement *setText(const QString &text_);

    virtual void addCopyTextToString(QString &str, uint32_t from = 0,
                                     uint32_t to = UINT32_MAX) const = 0;
    virtual int getSelectionIndexCount() const = 0;
    virtual void paint(QPainter &painter) = 0;
    virtual void paintAnimated(QPainter &painter, int yOffset) = 0;
    virtual int getMouseOverIndex(const QPoint &abs) const = 0;
    virtual int getXFromIndex(int index) = 0;

    const Link &getLink() const;
    const QString &getText() const;
    FlagsEnum<MessageElementFlag> getFlags() const;

protected:
    bool trailingSpace = true;

private:
    QString text_;
    QRect rect_;
    Link link_;
    MessageElement &creator_;
    int line_{};
};

// IMAGE
class ImageLayoutElement : public MessageLayoutElement
{
public:
    ImageLayoutElement(MessageElement &creator, ImagePtr image,
                       const QSize &size);

protected:
    void addCopyTextToString(QString &str, uint32_t from = 0,
                             uint32_t to = UINT32_MAX) const override;
    int getSelectionIndexCount() const override;
    void paint(QPainter &painter) override;
    void paintAnimated(QPainter &painter, int yOffset) override;
    int getMouseOverIndex(const QPoint &abs) const override;
    int getXFromIndex(int index) override;

    ImagePtr image_;
};

class ImageWithBackgroundLayoutElement : public ImageLayoutElement
{
public:
    ImageWithBackgroundLayoutElement(MessageElement &creator, ImagePtr image,
                                     const QSize &size, QColor color);

protected:
    void paint(QPainter &painter) override;

private:
    QColor color_;
};

class ImageWithCircleBackgroundLayoutElement : public ImageLayoutElement
{
public:
    ImageWithCircleBackgroundLayoutElement(MessageElement &creator,
                                           ImagePtr image,
                                           const QSize &imageSize, QColor color,
                                           int padding);

protected:
    void paint(QPainter &painter) override;

private:
    const QColor color_;
    const QSize imageSize_;
    const int padding_;
};

// TEXT
class TextLayoutElement : public MessageLayoutElement
{
public:
    TextLayoutElement(MessageElement &creator_, QString &text,
                      const QSize &size, QColor color_, FontStyle style_,
                      float scale_);

    void listenToLinkChanges();

protected:
    void addCopyTextToString(QString &str, uint32_t from = 0,
                             uint32_t to = UINT32_MAX) const override;
    int getSelectionIndexCount() const override;
    void paint(QPainter &painter) override;
    void paintAnimated(QPainter &painter, int yOffset) override;
    int getMouseOverIndex(const QPoint &abs) const override;
    int getXFromIndex(int index) override;

    QColor color_;
    FontStyle style_;
    float scale_;

    pajlada::Signals::SignalHolder managedConnections_;
};

// TEXT ICON
// two lines of text (characters) in the size of a normal chat badge
class TextIconLayoutElement : public MessageLayoutElement
{
public:
    TextIconLayoutElement(MessageElement &creator_, const QString &line1,
                          const QString &line2, float scale, const QSize &size);

protected:
    void addCopyTextToString(QString &str, uint32_t from = 0,
                             uint32_t to = UINT32_MAX) const override;
    int getSelectionIndexCount() const override;
    void paint(QPainter &painter) override;
    void paintAnimated(QPainter &painter, int yOffset) override;
    int getMouseOverIndex(const QPoint &abs) const override;
    int getXFromIndex(int index) override;

private:
    float scale;
    QString line1;
    QString line2;
};

class ReplyCurveLayoutElement : public MessageLayoutElement
{
public:
    ReplyCurveLayoutElement(MessageElement &creator, int width, float thickness,
                            float radius, float neededMargin);

protected:
    void paint(QPainter &painter) override;
    void paintAnimated(QPainter &painter, int yOffset) override;
    int getMouseOverIndex(const QPoint &abs) const override;
    int getXFromIndex(int index) override;
    void addCopyTextToString(QString &str, uint32_t from = 0,
                             uint32_t to = UINT32_MAX) const override;
    int getSelectionIndexCount() const override;

private:
    const QPen pen_;
    const float radius_;
    const float neededMargin_;
};

}  // namespace chatterino
