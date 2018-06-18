--- src/nuspell/dictionary.cxx.orig	2018-06-18 14:00:54.000000000 +0200
+++ src/nuspell/dictionary.cxx	2018-06-18 14:48:54.939059000 +0200
@@ -574,8 +574,8 @@
 
 template <Affixing_Mode m, class CharT>
 auto Dictionary::strip_prefix_only(std::basic_string<CharT>& word) const
-    -> boost::optional<
-        std::tuple<const string&, const Flag_Set&, const Prefix<CharT>&>>
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&,
+                                  const Prefix<CharT>&>>
 {
 	auto& dic = words;
 	auto& prefixes = get_structures<CharT>().prefixes;
@@ -617,7 +617,7 @@
 			    !word_flags.contains(compound_last_flag) &&
 			    !e.cont_flags.contains(compound_last_flag))
 				continue;
-			return {{word_entry.first, word_flags, e}};
+			return {{word, word_flags, e}};
 		}
 	}
 	return {};
@@ -625,8 +625,8 @@
 
 template <Affixing_Mode m, class CharT>
 auto Dictionary::strip_suffix_only(std::basic_string<CharT>& word) const
-    -> boost::optional<
-        std::tuple<const string&, const Flag_Set&, const Suffix<CharT>&>>
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&,
+                                  const Suffix<CharT>&>>
 {
 	auto& dic = words;
 	auto& suffixes = get_structures<CharT>().suffixes;
@@ -671,7 +671,7 @@
 			    !word_flags.contains(compound_last_flag) &&
 			    !e.cont_flags.contains(compound_last_flag))
 				continue;
-			return {{word_entry.first, word_flags, e}};
+			return {{word, word_flags, e}};
 		}
 	}
 	return {};
@@ -679,7 +679,7 @@
 
 template <Affixing_Mode m, class CharT>
 auto Dictionary::strip_prefix_then_suffix(std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&,
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&,
                                   const Suffix<CharT>&, const Prefix<CharT>&>>
 {
 	auto& prefixes = get_structures<CharT>().prefixes;
@@ -703,7 +703,7 @@
 template <Affixing_Mode m, class CharT>
 auto Dictionary::strip_pfx_then_sfx_2(const Prefix<CharT>& pe,
                                       std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&,
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&,
                                   const Suffix<CharT>&, const Prefix<CharT>&>>
 {
 	auto& dic = words;
@@ -733,7 +733,7 @@
 			    word_flags.contains(compound_onlyin_flag))
 				continue;
 			// needflag check here if needed
-			return {{word_entry.first, word_flags, se, pe}};
+			return {{word, word_flags, se, pe}};
 		}
 	}
 
@@ -742,7 +742,7 @@
 
 template <Affixing_Mode m, class CharT>
 auto Dictionary::strip_suffix_then_prefix(std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&,
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&,
                                   const Prefix<CharT>&, const Suffix<CharT>&>>
 {
 	auto& suffixes = get_structures<CharT>().suffixes;
@@ -766,7 +766,7 @@
 template <Affixing_Mode m, class CharT>
 auto Dictionary::strip_sfx_then_pfx_2(const Suffix<CharT>& se,
                                       std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&,
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&,
                                   const Prefix<CharT>&, const Suffix<CharT>&>>
 {
 	auto& dic = words;
@@ -796,7 +796,7 @@
 			    word_flags.contains(compound_onlyin_flag))
 				continue;
 			// needflag check here if needed
-			return {{word_entry.first, word_flags, pe, se}};
+			return {{word, word_flags, pe, se}};
 		}
 	}
 	return {};
@@ -804,7 +804,7 @@
 
 template <Affixing_Mode m, class CharT>
 auto Dictionary::strip_suffix_then_suffix(std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&,
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&,
                                   const Suffix<CharT>&, const Suffix<CharT>&>>
 {
 	auto& suffixes = get_structures<CharT>().suffixes;
@@ -828,7 +828,7 @@
 template <Affixing_Mode m, class CharT>
 auto Dictionary::strip_sfx_then_sfx_2(const Suffix<CharT>& se1,
                                       std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&,
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&,
                                   const Suffix<CharT>&, const Suffix<CharT>&>>
 {
 
@@ -856,7 +856,7 @@
 			//    word_flags.contains(compound_onlyin_flag))
 			//	continue;
 			// needflag check here if needed
-			return {{word_entry.first, word_flags, se2, se1}};
+			return {{word, word_flags, se2, se1}};
 		}
 	}
 	return {};
@@ -864,7 +864,7 @@
 
 template <Affixing_Mode m, class CharT>
 auto Dictionary::strip_prefix_then_prefix(std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&,
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&,
                                   const Prefix<CharT>&, const Prefix<CharT>&>>
 {
 	auto& prefixes = get_structures<CharT>().prefixes;
@@ -888,7 +888,7 @@
 template <Affixing_Mode m, class CharT>
 auto Dictionary::strip_pfx_then_pfx_2(const Prefix<CharT>& pe1,
                                       std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&,
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&,
                                   const Prefix<CharT>&, const Prefix<CharT>&>>
 {
 	auto& dic = words;
@@ -915,15 +915,16 @@
 			//    word_flags.contains(compound_onlyin_flag))
 			//	continue;
 			// needflag check here if needed
-			return {{word_entry.first, word_flags, pe2, pe1}};
+			return {{word, word_flags, pe2, pe1}};
 		}
 	}
 	return {};
 }
 
 template <Affixing_Mode m, class CharT>
-auto Dictionary::strip_prefix_then_2_suffixes(std::basic_string<CharT>& word)
-    const -> boost::optional<std::tuple<const string&, const Flag_Set&>>
+auto Dictionary::strip_prefix_then_2_suffixes(
+    std::basic_string<CharT>& word) const
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&>>
 {
 	auto& prefixes = get_structures<CharT>().prefixes;
 	auto& suffixes = get_structures<CharT>().suffixes;
@@ -960,7 +961,7 @@
 auto Dictionary::strip_pfx_2_sfx_3(const Prefix<CharT>& pe1,
                                    const Suffix<CharT>& se1,
                                    std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&>>
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&>>
 {
 	auto& dic = words;
 	auto& suffixes = get_structures<CharT>().suffixes;
@@ -989,7 +990,7 @@
 			//    word_flags.contains(compound_onlyin_flag))
 			//	continue;
 			// needflag check here if needed
-			return {{word_entry.first, word_flags}};
+			return {{word, word_flags}};
 		}
 	}
 
@@ -997,8 +998,9 @@
 }
 
 template <Affixing_Mode m, class CharT>
-auto Dictionary::strip_suffix_prefix_suffix(std::basic_string<CharT>& word)
-    const -> boost::optional<std::tuple<const string&, const Flag_Set&>>
+auto Dictionary::strip_suffix_prefix_suffix(
+    std::basic_string<CharT>& word) const
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&>>
 {
 	auto& prefixes = get_structures<CharT>().prefixes;
 	auto& suffixes = get_structures<CharT>().suffixes;
@@ -1033,7 +1035,7 @@
 auto Dictionary::strip_s_p_s_3(const Suffix<CharT>& se1,
                                const Prefix<CharT>& pe1,
                                std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&>>
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&>>
 {
 	auto& dic = words;
 	auto& suffixes = get_structures<CharT>().suffixes;
@@ -1067,7 +1069,7 @@
 			//    word_flags.contains(compound_onlyin_flag))
 			//	continue;
 			// needflag check here if needed
-			return {{word_entry.first, word_flags}};
+			return {{word, word_flags}};
 		}
 	}
 
@@ -1075,8 +1077,9 @@
 }
 
 template <Affixing_Mode m, class CharT>
-auto Dictionary::strip_2_suffixes_then_prefix(std::basic_string<CharT>& word)
-    const -> boost::optional<std::tuple<const string&, const Flag_Set&>>
+auto Dictionary::strip_2_suffixes_then_prefix(
+    std::basic_string<CharT>& word) const
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&>>
 {
 	auto& suffixes = get_structures<CharT>().suffixes;
 
@@ -1110,7 +1113,7 @@
 auto Dictionary::strip_2_sfx_pfx_3(const Suffix<CharT>& se1,
                                    const Suffix<CharT>& se2,
                                    std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&>>
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&>>
 {
 	auto& dic = words;
 	auto& prefixes = get_structures<CharT>().prefixes;
@@ -1140,7 +1143,7 @@
 			//    word_flags.contains(compound_onlyin_flag))
 			//	continue;
 			// needflag check here if needed
-			return {{word_entry.first, word_flags}};
+			return {{word, word_flags}};
 		}
 	}
 
@@ -1148,8 +1151,9 @@
 }
 
 template <Affixing_Mode m, class CharT>
-auto Dictionary::strip_suffix_then_2_prefixes(std::basic_string<CharT>& word)
-    const -> boost::optional<std::tuple<const string&, const Flag_Set&>>
+auto Dictionary::strip_suffix_then_2_prefixes(
+    std::basic_string<CharT>& word) const
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&>>
 {
 	auto& prefixes = get_structures<CharT>().prefixes;
 	auto& suffixes = get_structures<CharT>().suffixes;
@@ -1186,7 +1190,7 @@
 auto Dictionary::strip_sfx_2_pfx_3(const Suffix<CharT>& se1,
                                    const Prefix<CharT>& pe1,
                                    std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&>>
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&>>
 {
 	auto& dic = words;
 	auto& prefixes = get_structures<CharT>().prefixes;
@@ -1214,7 +1218,7 @@
 			// if (m == FULL_WORD &&
 			//    word_flags.contains(compound_onlyin_flag))
 			//	continue;
-			return {{word_entry.first, word_flags}};
+			return {{word, word_flags}};
 		}
 	}
 
@@ -1222,8 +1226,9 @@
 }
 
 template <Affixing_Mode m, class CharT>
-auto Dictionary::strip_prefix_suffix_prefix(std::basic_string<CharT>& word)
-    const -> boost::optional<std::tuple<const string&, const Flag_Set&>>
+auto Dictionary::strip_prefix_suffix_prefix(
+    std::basic_string<CharT>& word) const
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&>>
 {
 	auto& prefixes = get_structures<CharT>().prefixes;
 	auto& suffixes = get_structures<CharT>().suffixes;
@@ -1258,7 +1263,7 @@
 auto Dictionary::strip_p_s_p_3(const Prefix<CharT>& pe1,
                                const Suffix<CharT>& se1,
                                std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&>>
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&>>
 {
 	auto& dic = words;
 	auto& prefixes = get_structures<CharT>().prefixes;
@@ -1291,7 +1296,7 @@
 			// if (m == FULL_WORD &&
 			//    word_flags.contains(compound_onlyin_flag))
 			//	continue;
-			return {{word_entry.first, word_flags}};
+			return {{word, word_flags}};
 		}
 	}
 
@@ -1299,8 +1304,9 @@
 }
 
 template <Affixing_Mode m, class CharT>
-auto Dictionary::strip_2_prefixes_then_suffix(std::basic_string<CharT>& word)
-    const -> boost::optional<std::tuple<const string&, const Flag_Set&>>
+auto Dictionary::strip_2_prefixes_then_suffix(
+    std::basic_string<CharT>& word) const
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&>>
 {
 	auto& prefixes = get_structures<CharT>().prefixes;
 
@@ -1334,7 +1340,7 @@
 auto Dictionary::strip_2_pfx_sfx_3(const Prefix<CharT>& pe1,
                                    const Prefix<CharT>& pe2,
                                    std::basic_string<CharT>& word) const
-    -> boost::optional<std::tuple<const string&, const Flag_Set&>>
+    -> boost::optional<std::tuple<std::basic_string<CharT>, const Flag_Set&>>
 {
 	auto& dic = words;
 	auto& suffixes = get_structures<CharT>().suffixes;
@@ -1363,7 +1369,7 @@
 			// if (m == FULL_WORD &&
 			//    word_flags.contains(compound_onlyin_flag))
 			//	continue;
-			return {{word_entry.first, word_flags}};
+			return {{word, word_flags}};
 		}
 	}
 
