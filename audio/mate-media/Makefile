# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-media
PORTVERSION=	1.8.0
CATEGORIES=	audio mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Multimedia applications for the MATE desktop

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libcanberra-gtk.so:${PORTSDIR}/audio/libcanberra

PORTSCOUT=	limitw:1,even

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_MATE=	desktop panel
USE_GNOME=	glib20 gtk20 intlhack libxml2
USE_LDCONFIG=	yes
USE_GSTREAMER=	good
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-pulseaudio \
		--enable-gst-mixer-applet
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.panel.applet.mixer.gschema.xml \
		org.mate.volume-control.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|mixer_applet2|mate_mixer_applet2|g' \
		${WRKSRC}/gst-mixer-applet/Makefile.in \
		${WRKSRC}/gst-mixer-applet/load.c \
		${WRKSRC}/gst-mixer-applet/org.mate.panel.applet.MixerAppletFactory.service.in \
		${WRKSRC}/gst-mixer-applet/org.mate.applets.MixerApplet.mate-panel-applet.in.in

.include <bsd.port.mk>
