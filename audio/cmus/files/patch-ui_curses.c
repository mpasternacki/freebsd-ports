--- ui_curses.c.orig	2015-03-08 18:56:08.866634000 +0100
+++ ui_curses.c	2015-03-08 18:57:57.639463000 +0100
@@ -76,6 +76,9 @@
 /* TIOCGWINSZ */
 #include <termios.h>
 #include <ncurses.h>
+#elif defined(__FreeBSD__)
+#define NCURSES_WIDECHAR 1
+#include <ncurses/ncurses.h>
 #else
 #include <curses.h>
 #endif
