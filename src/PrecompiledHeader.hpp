#ifdef __cplusplus
#    include <boost/current_function.hpp>
#    include <boost/foreach.hpp>
#    include <boost/noncopyable.hpp>
#    include <boost/optional.hpp>
#    include <IrcCommand>
#    include <IrcConnection>
#    include <IrcMessage>
#    include <pajlada/serialize.hpp>
#    include <pajlada/settings/setting.hpp>
#    include <pajlada/settings/settinglistener.hpp>
#    include <pajlada/signals/connection.hpp>
#    include <pajlada/signals/signal.hpp>
#    include <QAbstractListModel>
#    include <QAbstractNativeEventFilter>
#    include <QAction>
#    include <QApplication>
#    include <QBrush>
#    include <QBuffer>
#    include <QButtonGroup>
#    include <QByteArray>
#    include <QCheckBox>
#    include <QClipboard>
#    include <QColor>
#    include <QComboBox>
#    include <QCompleter>
#    include <QCoreApplication>
#    include <QDateTime>
#    include <QDebug>
#    include <QDesktopServices>
#    include <QDialog>
#    include <QDialogButtonBox>
#    include <QDir>
#    include <QDockWidget>
#    include <QDrag>
#    include <QDragEnterEvent>
#    include <QElapsedTimer>
#    include <QEventLoop>
#    include <QFile>
#    include <QFileDialog>
#    include <QFileInfo>
#    include <QFlags>
#    include <QFont>
#    include <QFontDatabase>
#    include <QFontDialog>
#    include <QFontMetrics>
#    include <QFormLayout>
#    include <QGraphicsBlurEffect>
#    include <QGroupBox>
#    include <QHBoxLayout>
#    include <QHeaderView>
#    include <QIcon>
#    include <QImageReader>
#    include <QJsonArray>
#    include <QJsonDocument>
#    include <QJsonObject>
#    include <QJsonValue>
#    include <QKeyEvent>
#    include <QLabel>
#    include <QLayout>
#    include <QLibrary>
#    include <QLineEdit>
#    include <QList>
#    include <QListView>
#    include <QListWidget>
#    include <QMap>
#    include <QMediaPlayer>
#    include <QMenu>
#    include <QMessageBox>
#    include <QMimeData>
#    include <QMouseEvent>
#    include <QMutex>
#    include <QMutexLocker>
#    include <QNetworkAccessManager>
#    include <QNetworkReply>
#    include <QNetworkRequest>
#    include <QObject>
#    include <QPainter>
#    include <QPainterPath>
#    include <QPaintEvent>
#    include <QPalette>
#    include <QPixmap>
#    include <QPoint>
#    include <QProcess>
#    include <QPropertyAnimation>
#    include <QPushButton>
#    include <QRadialGradient>
#    include <QRect>
#    include <QRegularExpression>
#    include <QRunnable>
#    include <QScroller>
#    include <QShortcut>
#    include <QSizePolicy>
#    include <QSlider>
#    include <QSpinBox>
#    include <QStackedLayout>
#    include <QStandardPaths>
#    include <QString>
#    include <QStyle>
#    include <QStyleOption>
#    include <QTabWidget>
#    include <QtCore/QVariant>
#    include <QTextEdit>
#    include <QtGlobal>
#    include <QThread>
#    include <QThreadPool>
#    include <QTime>
#    include <QTimer>
#    include <QtWidgets/QAction>
#    include <QtWidgets/QApplication>
#    include <QtWidgets/QButtonGroup>
#    include <QtWidgets/QDialog>
#    include <QtWidgets/QDialogButtonBox>
#    include <QtWidgets/QFormLayout>
#    include <QtWidgets/QHBoxLayout>
#    include <QtWidgets/QHeaderView>
#    include <QtWidgets/QLabel>
#    include <QtWidgets/QLineEdit>
#    include <QtWidgets/QPushButton>
#    include <QtWidgets/QTabWidget>
#    include <QtWidgets/QVBoxLayout>
#    include <QUrl>
#    include <QUuid>
#    include <QVariant>
#    include <QVBoxLayout>
#    include <QVector>
#    include <QWheelEvent>
#    include <QWidget>
#    include <rapidjson/document.h>
#    include <rapidjson/error/en.h>
#    include <rapidjson/error/error.h>

#    include <algorithm>
#    include <cassert>
#    include <chrono>
#    include <cinttypes>
#    include <climits>
#    include <cmath>
#    include <cstdint>
#    include <ctime>
#    include <functional>
#    include <future>
#    include <list>
#    include <map>
#    include <memory>
#    include <mutex>
#    include <random>
#    include <set>
#    include <string>
#    include <thread>
#    include <tuple>
#    include <type_traits>
#    include <unordered_map>
#    include <unordered_set>
#    include <vector>

#    ifndef UNUSED
#        define UNUSED(x) (void)(x)
#    endif

#    ifndef ATTR_UNUSED
#        ifdef Q_OS_WIN
#            define ATTR_UNUSED
#        else
#            define ATTR_UNUSED __attribute__((unused))
#        endif
#    endif

#endif
