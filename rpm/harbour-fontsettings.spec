Name:       harbour-fontsettings
Version:    0.3.0
Release:    1
Summary:    Font manager for Sailfish OS
License:    MIT
URL:        https://github.com/zenevo/harbour-fontsettings
Source0:    %{name}-%{version}.tar.gz
BuildRequires:  pkgconfig(Qt5Quick)
BuildRequires:  pkgconfig(Qt5Qml)
BuildRequires:  pkgconfig(sailfishapp)
BuildRequires:  qt5-qtdeclarative-devel

# Runtime: QML modules and command line helpers the app uses.
# The Qt/Sailfish shared libraries themselves are picked up automatically as
# soname dependencies by rpmbuild; these cover what it cannot see.
Requires:       sailfishsilica-qt5
Requires:       sailfish-components-pickers-qt5
Requires:       qt5-qtdeclarative-import-qtquick2plugin
Requires:       qt5-qtdeclarative-import-window2
Requires:       fontconfig
Requires:       dconf

%description
A small Sailfish OS application to change the system UI font: import
.ttf/.otf/.ttc files, pick a primary/heading/monospace family, keep an
ordered fallback chain, and apply everything through a per-user fontconfig
configuration (no system files are modified).

%prep
%setup -q

%build
qmake
make %{?_smp_mflags}

%install
make install INSTALL_ROOT=%{buildroot}
mkdir -p %{buildroot}/usr/share/harbour-fontsettings/qml
cp -r qml/* %{buildroot}/usr/share/harbour-fontsettings/qml/
find %{buildroot}/usr/share/harbour-fontsettings -type d -exec chmod 755 {} +
find %{buildroot}/usr/share/harbour-fontsettings -type f -exec chmod 644 {} +
install -D -m 644 data/harbour-fontsettings.desktop \
    %{buildroot}/usr/share/applications/harbour-fontsettings.desktop
for s in 86 108 128 172 256; do
    install -D -m 644 icons/harbour-fontsettings-$s.png \
        %{buildroot}/usr/share/icons/hicolor/${s}x${s}/apps/harbour-fontsettings.png
done
install -D -m 644 icons/harbour-fontsettings.svg \
    %{buildroot}/usr/share/icons/hicolor/scalable/apps/harbour-fontsettings.svg

%files
/usr/bin/harbour-fontsettings
/usr/share/harbour-fontsettings
/usr/share/applications/harbour-fontsettings.desktop
/usr/share/icons/hicolor/*/apps/harbour-fontsettings.*

%changelog
* Wed Nov 11 2026 zen <zen@localhost> - 0.3.0-1
- Declare runtime dependencies explicitly (Silica, Pickers, fontconfig, dconf)
* Wed Nov 11 2026 zen <zen@localhost> - 0.2.6-1
- Gradient runs bottom-left to top-right
* Wed Nov 11 2026 zen <zen@localhost> - 0.2.5-1
- Icon silhouette matches the qtodo launcher icon exactly (squared top-right)
* Wed Nov 11 2026 zen <zen@localhost> - 0.2.4-1
- Vector icon traced from the stock plate, rendered per size (crisper edges)
* Wed Nov 11 2026 zen <zen@localhost> - 0.2.3-1
- Icon built directly from the stock plate alpha, recoloured with the gradient
* Wed Nov 11 2026 zen <zen@localhost> - 0.2.2-1
- Icon silhouette matched to the stock Sailfish people icon
* Wed Nov 11 2026 zen <zen@localhost> - 0.2.1-1
- New launcher icon: speech-bubble silhouette with gradient fill
* Wed Nov 11 2026 zen <zen@localhost> - 0.2.0-1
- Only redirect the primary family; fallbacks are the system defaults again
* Wed Nov 11 2026 zen <zen@localhost> - 0.1.4-1
- Fix button anchoring inside the fallback footer
* Wed Nov 11 2026 zen <zen@localhost> - 0.1.3-1
- Keep Sail Sans Pro as the final fallback; show it in the fallback page
* Wed Nov 11 2026 zen <zen@localhost> - 0.1.2-1
- Return to the main page after picking a font file
* Wed Nov 11 2026 zen <zen@localhost> - 0.1.0-1
- Initial package
