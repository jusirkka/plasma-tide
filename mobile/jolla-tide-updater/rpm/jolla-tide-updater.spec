# 
# Do NOT Edit the Auto-generated Part!
# Generated by: spectacle version 0.27
# 

Name:       jolla-tide-updater

# >> macros
# << macros

%{!?qtc_qmake:%define qtc_qmake %qmake}
%{!?qtc_qmake5:%define qtc_qmake5 %qmake5}
%{!?qtc_make:%define qtc_make make}
%{?qtc_builddir:%define _builddir %qtc_builddir}
Summary:    Keeps active jolla-tide stations updated.
Version:    0.1
Release:    1
Group:      Qt/Qt
License:    LICENSE
URL:        https://github.com/kvanttiapina/jolla-tide
Source0:    %{name}-%{version}.tar.bz2
Source100:  jolla-tide-updater.yaml
BuildRequires:  pkgconfig(Qt5Core)
BuildRequires:  pkgconfig(Qt5Sql)
BuildRequires:  pkgconfig(Qt5Xml)
BuildRequires:  pkgconfig(Qt5DBus)
BuildRequires:  pkgconfig(Qt5Network)

%description
%{summary}.

%prep
%setup -q -n %{name}-%{version}

# >> setup
# << setup

%build
# >> build pre
# << build pre

%qtc_qmake5 

%qtc_make %{?_smp_mflags}

# >> build post
# << build post

%install
rm -rf %{buildroot}
# >> install pre
systemctl --user --no-reload disable %{name}.service || true
systemctl --user stop %{name}.service || true
# << install pre
%qmake5_install

# >> install post
systemctl --user enable %{name}.service || true
systemctl --user start %{name}.service || true
# << install post

%files
%defattr(-,root,root,-)
%{_bindir}/%{name}
%{_userunitdir}/%{name}.service
# >> files
# << files
