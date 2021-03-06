# $FreeBSD$

PORTNAME=	libvisio
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	textproc devel
MASTER_SITES=	http://dev-www.libreoffice.org/src/${PORTNAME}/
PKGNAMESUFFIX=	01

MAINTAINER=	office@FreeBSD.org
COMMENT=	Library and tools for parsing the visio file format structure

LICENSE=	LGPL21 MPL GPLv2
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/include/boost/spirit/include/classic_core.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libicui18n.so:${PORTSDIR}/devel/icu \
		librevenge-0.0.so:${PORTSDIR}/textproc/librevenge

CONFIGURE_ARGS=	--disable-tests --disable-werror --without-docs
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_GNOME=	libxml2
USES=		gmake gperf libtool pathfix perl5 pkgconfig tar:xz
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e "s,zlib,,g" ${WRKSRC}/libvisio.pc.in

.include <bsd.port.mk>
