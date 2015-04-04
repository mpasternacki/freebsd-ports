diff --git c/vendor/libjitsi/src/native/portaudio/org_jitsi_impl_neomedia_portaudio_Pa.c w/vendor/libjitsi/src/native/portaudio/org_jitsi_impl_neomedia_portaudio_Pa.c
index 0be4948..01be811 100644
--- libjitsi/src/native/portaudio/org_jitsi_impl_neomedia_portaudio_Pa.c.orig
+++ libjitsi/src/native/portaudio/org_jitsi_impl_neomedia_portaudio_Pa.c
@@ -222,12 +222,12 @@ JNIEXPORT jbyteArray JNICALL
 Java_org_jitsi_impl_neomedia_portaudio_Pa_DeviceInfo_1getDeviceUIDBytes
     (JNIEnv *env, jclass clazz, jlong deviceInfo)
 {
-    PaDeviceInfo *di = (PaDeviceInfo *) (intptr_t) deviceInfo;
+    /* PaDeviceInfo *di = (PaDeviceInfo *) (intptr_t) deviceInfo; */
 
-    return
-        (di->structVersion >= 3)
-            ? PortAudio_getStrBytes(env, di->deviceUID)
-            : NULL;
+    return NULL;
+        /* (di->structVersion >= 3) */
+        /*     ? PortAudio_getStrBytes(env, di->deviceUID) */
+        /*     : NULL; */
 }
 
 JNIEXPORT jint JNICALL
@@ -279,12 +279,13 @@ JNIEXPORT jbyteArray JNICALL
 Java_org_jitsi_impl_neomedia_portaudio_Pa_DeviceInfo_1getTransportTypeBytes
     (JNIEnv *env, jclass clazz, jlong deviceInfo)
 {
-    PaDeviceInfo *di = (PaDeviceInfo *) (intptr_t) deviceInfo;
+    return NULL;
+    /* PaDeviceInfo *di = (PaDeviceInfo *) (intptr_t) deviceInfo; */
 
-    return
-        (di->structVersion >= 3)
-            ? PortAudio_getStrBytes(env, di->transportType)
-            : NULL;
+    /* return */
+    /*     (di->structVersion >= 3) */
+    /*         ? PortAudio_getStrBytes(env, di->transportType) */
+    /*         : NULL; */
 }
 
 JNIEXPORT void JNICALL
