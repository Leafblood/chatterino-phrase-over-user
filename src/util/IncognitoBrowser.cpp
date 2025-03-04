#include "util/IncognitoBrowser.hpp"

#include <QProcess>
#include <QRegularExpression>
#include <QSettings>
#include <QVariant>

namespace {

using namespace chatterino;

#ifdef Q_OS_WIN
QString injectPrivateSwitch(QString command)
{
    // list of command line switches to turn on private browsing in browsers
    static auto switches = std::vector<std::pair<QString, QString>>{
        {"firefox", "-private-window"},  {"librewolf", "-private-window"},
        {"waterfox", "-private-window"}, {"icecat", "-private-window"},
        {"chrome", "-incognito"},        {"vivaldi", "-incognito"},
        {"opera", "-newprivatetab"},     {"opera\\\\launcher", "--private"},
        {"iexplore", "-private"},        {"msedge", "-inprivate"},
    };

    // transform into regex and replacement string
    std::vector<std::pair<QRegularExpression, QString>> replacers;
    for (const auto &switch_ : switches)
    {
        replacers.emplace_back(
            QRegularExpression("(" + switch_.first + "\\.exe\"?).*",
                               QRegularExpression::CaseInsensitiveOption),
            "\\1 " + switch_.second);
    }

    // try to find matching regex and apply it
    for (const auto &replacement : replacers)
    {
        if (replacement.first.match(command).hasMatch())
        {
            command.replace(replacement.first, replacement.second);
            return command;
        }
    }

    // couldn't match any browser -> unknown browser
    return QString();
}

QString getCommand(const QString &link)
{
    // get default browser prog id
    auto browserId = QSettings("HKEY_CURRENT_"
                               "USER\\Software\\Microsoft\\Windows\\Shell\\"
                               "Associations\\UrlAssociatio"
                               "ns\\http\\UserChoice",
                               QSettings::NativeFormat)
                         .value("Progid")
                         .toString();

    // get default browser start command
    auto command =
        QSettings("HKEY_CLASSES_ROOT\\" + browserId + "\\shell\\open\\command",
                  QSettings::NativeFormat)
            .value("Default")
            .toString();
    if (command.isNull())
    {
        return QString();
    }

    // inject switch to enable private browsing
    command = injectPrivateSwitch(command);
    if (command.isNull())
    {
        return QString();
    }

    // link
    command += " " + link;

    return command;
}
#endif

}  // namespace

namespace chatterino {

bool supportsIncognitoLinks()
{
#ifdef Q_OS_WIN
    return !getCommand("").isNull();
#else
    return false;
#endif
}

bool openLinkIncognito(const QString &link)
{
#ifdef Q_OS_WIN
    auto command = getCommand(link);

    // TODO: split command into program path and incognito argument
    return QProcess::startDetached(command, {});
#else
    return false;
#endif
}

}  // namespace chatterino
