#ifndef FONTBACKEND_H
#define FONTBACKEND_H

#include <QObject>
#include <QStringList>
#include <QVariantList>

class FontBackend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList families READ families NOTIFY familiesChanged)
    Q_PROPERTY(QVariantList importedFonts READ importedFonts NOTIFY familiesChanged)
    Q_PROPERTY(QString primary READ primary WRITE setPrimary NOTIFY selectionChanged)
    Q_PROPERTY(QString heading READ heading WRITE setHeading NOTIFY selectionChanged)
    Q_PROPERTY(QString mono READ mono WRITE setMono NOTIFY selectionChanged)
    Q_PROPERTY(QStringList fallbacks READ fallbacks NOTIFY fallbacksChanged)
    Q_PROPERTY(QString defaultFamily READ defaultFamily CONSTANT)
    Q_PROPERTY(QString lastMessage READ lastMessage NOTIFY messageChanged)
    Q_PROPERTY(bool configured READ isConfigured NOTIFY selectionChanged)

public:
    explicit FontBackend(QObject *parent = nullptr);

    QStringList families();
    QVariantList importedFonts() const { return m_imported; }

    QString primary() const { return m_primary; }
    QString heading() const { return m_heading; }
    QString mono() const { return m_mono; }
    QStringList fallbacks() const { return m_fallbacks; }
    QString defaultFamily() const;
    QString lastMessage() const { return m_message; }
    bool isConfigured() const;

    void setPrimary(const QString &family);
    void setHeading(const QString &family);
    void setMono(const QString &family);

    Q_INVOKABLE void refresh();
    Q_INVOKABLE bool importFont(const QString &path);
    Q_INVOKABLE bool removeImported(const QString &path);
    Q_INVOKABLE void addFallback(const QString &family);
    Q_INVOKABLE void removeFallback(const QString &family);
    Q_INVOKABLE void moveFallback(int from, int to);
    Q_INVOKABLE bool apply();
    Q_INVOKABLE bool reset();
    Q_INVOKABLE bool restartHomeScreen();
    Q_INVOKABLE int runCli(const QStringList &args);

signals:
    void familiesChanged();
    void selectionChanged();
    void fallbacksChanged();
    void messageChanged();

private:
    QString fontDir() const;
    QString configDir() const;
    QString configPath() const;
    QString statePath() const;
    QString buildConfig() const;
    bool configIsOurs() const;
    void loadState();
    void saveState();
    void setMessage(const QString &msg);
    void runFcCache();
    bool dconfWrite(const QString &key, const QString &value);
    bool dconfReset(const QString &key);
    QString familyOfFile(const QString &path) const;
    QStringList installedFamiliesFromFc() const;

    QStringList m_families;
    QVariantList m_imported;
    QString m_primary;
    QString m_heading;
    QString m_mono;
    QStringList m_fallbacks;
    QString m_message;
};

#endif // FONTBACKEND_H
