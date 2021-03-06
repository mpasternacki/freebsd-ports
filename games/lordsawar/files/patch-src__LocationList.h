--- src/LocationList.h.orig	2010-05-11 08:50:34 UTC
+++ src/LocationList.h
@@ -55,7 +55,7 @@ template<class T> class LocationList : p
 
   void add(T t)
     {
-      push_back(t);
+      this->push_back(t);
       d_id[t->getId()] = t;
       int size = t->getSize();
       for (int i = 0; i < size; i++)
@@ -74,8 +74,14 @@
 	for (int j = 0; j < size; j++)
 	  {
 	    Vector<int> pos = t->getPos() + Vector<int>(i,j);
+#if defined(_LIBCPP_VERSION)
+            typename PositionMap::const_iterator it = d_object.find(pos);
+            if (it != d_object.end())
+              d_object.erase(it);
+#else
             if (d_object.find(pos) != d_object.end())
               d_object.erase(d_object.find(pos));
+#endif
 	  }
       delete t;
     }
