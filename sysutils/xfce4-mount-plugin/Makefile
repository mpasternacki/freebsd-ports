# Created by: Olivier Duchateau <duchateau.olivier@gmail.com>
# $FreeBSD$

PORTNAME=	xfce4-mount-plugin
PORTVERSION=	0.6.7
PORTREVISION=	2
CATEGORIES=	sysutils xfce
MASTER_SITES=	XFCE/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Mount and umount utility for the Xfce4 panel

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
USES=		gettext gmake libtool pkgconfig xfce tar:bzip2
USE_GNOME=	intltool intlhack
USE_LDCONFIG=	yes
USE_XFCE=	panel

.include <bsd.port.mk>
