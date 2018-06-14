--- tests/dictionary_test.cxx.orig	2018-06-13 20:45:09 UTC
+++ tests/dictionary_test.cxx
@@ -54,9 +54,15 @@ TEST_CASE("suffixes", "[dictionary]")
 	auto d = Dictionary();
 	d.set_encoding_and_language("UTF-8");
 
-	d.words.emplace("berry", u"T");
-	d.words.emplace("May", u"T");
-	d.words.emplace("vary", u"");
+	d.words.emplace(std::piecewise_construct,
+			std::forward_as_tuple("berry"),
+			std::forward_as_tuple(u"T"));
+	d.words.emplace(std::piecewise_construct,
+			std::forward_as_tuple("May"),
+			std::forward_as_tuple(u"T"));
+	d.words.emplace(std::piecewise_construct,
+			std::forward_as_tuple("vary"),
+			std::forward_as_tuple(u""));
 
 	d.structures.suffixes.emplace(u'T', true, "y"s, "ies"s, Flag_Set(),
 	                              ".[^aeiou]y"s);
