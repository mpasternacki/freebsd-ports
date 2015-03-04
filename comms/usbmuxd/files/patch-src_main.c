https://github.com/awilfox/usbmuxd/commit/f6569bfdac0c3020c0f91b679370b8894827586b
--- src/main.c
+++ src/main.c
@@ -159,7 +159,7 @@ static void set_signal_handlers(void)
        sigaction(SIGUSR2, &sa, NULL);
 }
 
-#if defined(__FreeBSD__) || defined(__APPLE__)
+#if (defined(__FreeBSD__) && __FreeBSD__ < 11) || defined(__APPLE__)
 static int ppoll(struct pollfd *fds, nfds_t nfds, const struct timespec *timeout, const sigset_t *sigmask)
 {
        int ready;
