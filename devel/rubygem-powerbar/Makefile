# Created by: Michael Moll <kvedulv at kvedulv.de>
# $FreeBSD$

PORTNAME=	powerbar
PORTVERSION=	1.0.12
CATEGORIES=	devel ruby
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Progressbar library for Ruby

LICENSE=	MIT

RUN_DEPENDS=	rubygem-ansi>=1.5.0:${PORTSDIR}/devel/rubygem-ansi \
		rubygem-hashie>=1.1.0:${PORTSDIR}/devel/rubygem-hashie

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/powerbar-demo

.include <bsd.port.mk>
