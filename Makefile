# $FreeBSD$

PORTNAME=	nuspell
PORTVERSION=	g20180612
CATEGORIES=	textproc

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Modern C++ spell checking library based on Hunspell

LICENSE=	GPLv2+ LGPL21+ LGPL3 MPL11
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2+=	${_LICENSE_STORE}/GPLv2
LICENSE_FILE_LGPL21+=	${_LICENSE_STORE}/LGPL21
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LESSER
LICENSE_FILE_MPL11=	${_LICENSE_STORE}/MPL11

BUILD_DEPENDS=	bash:shells/bash \
		wget:ftp/wget
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libicuuc.so:devel/icu

CONFLICTS_INSTALL=	tinker-[0-9]*

USES=		autoreconf compiler:c++14-lang iconv libtool:keepla ncurses \
		pathfix perl5 pkgconfig readline shebangfix
SHEBANG_FILES=	src/tools/ispellaff2myspell tests/test.sh
USE_LDCONFIG=	yes
USE_PERL5=	run
CONFIGURE_ARGS=	--with-readline --with-ui
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

USE_GITHUB=	yes
GH_ACCOUNT=	hunspell
GH_TAGNAME=	438e6e5

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/src/tools/hunspell.cxx

makepatch-clean:
	@${RM} ${WRKSRC}/tests/suggestiontest/Makefile.orig

.include <bsd.port.mk>

# XXX Don't override definition in Mk/bsd.port.mk
makepatch:	makepatch-clean