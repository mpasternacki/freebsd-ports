# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-DispatchType-Regex
PORTVERSION=	5.90035
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Regex DispatchType

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.90060:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Text-Balanced>=0:${PORTSDIR}/textproc/p5-Text-Balanced \
		p5-Text-SimpleTable>=0:${PORTSDIR}/textproc/p5-Text-SimpleTable
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean

USE_PERL5=	modbuild
USES=		perl5

.include <bsd.port.mk>
