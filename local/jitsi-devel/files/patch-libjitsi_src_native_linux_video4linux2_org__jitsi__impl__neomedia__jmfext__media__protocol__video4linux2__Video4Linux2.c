diff --git c/vendor/libjitsi/src/native/linux/video4linux2/org_jitsi_impl_neomedia_jmfext_media_protocol_video4linux2_Video4Linux2.c w/vendor/libjitsi/src/native/linux/video4linux2/org_jitsi_impl_neomedia_jmfext_media_protocol_video4linux2_Video4Linux2.c
index fdd3988..13c77c6 100644
--- libjitsi/src/native/linux/video4linux2/org_jitsi_impl_neomedia_jmfext_media_protocol_video4linux2_Video4Linux2.c.orig
+++ libjitsi/src/native/linux/video4linux2/org_jitsi_impl_neomedia_jmfext_media_protocol_video4linux2_Video4Linux2.c
@@ -36,7 +36,11 @@ JNIEXPORT jint JNICALL
 Java_org_jitsi_impl_neomedia_jmfext_media_protocol_video4linux2_Video4Linux2_ioctl
     (JNIEnv *jniEnv, jclass clazz, jint fd, jint request, jlong argp)
 {
+#ifdef __FreeBSD__
+    return ioctl(fd, (unsigned long)request, (void *) (intptr_t) argp);
+#else
     return ioctl(fd, request, (void *) (intptr_t) argp);
+#endif
 }
 
 JNIEXPORT jlong JNICALL
