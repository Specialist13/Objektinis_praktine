#include "headers.h"

int main() {
    std::setlocale(LC_ALL, "");
    std::map<std::string, int> zodziu_pasikartojimas;
    std::string zodis;
    std::ifstream fd("tekstas.txt");
    std::stringstream ss;
    ss << fd.rdbuf();
    fd.close();

    while (ss >> zodis) {
        // Convert to ICU UnicodeString (UTF-8)
        icu::UnicodeString ustr = icu::UnicodeString::fromUTF8(zodis);

        // Remove all characters that are NOT letters (unicode-aware)
        icu::UnicodeString cleaned;
        for (int32_t i = 0; i < ustr.length(); ++i) {
            UChar32 c = ustr.char32At(i);
            if (u_isalpha(c)) {  // keep only letters
                cleaned.append(c);
            }
            if (U_IS_SUPPLEMENTARY(c)) {
                ++i; // skip the trailing surrogate of supplementary char
            }
        }

        // Convert to lowercase with ICU (locale-neutral, Unicode-aware)
        cleaned.toLower();

        // Convert back to UTF-8 std::string
        std::string lower_utf8;
        cleaned.toUTF8String(lower_utf8);

        if (!lower_utf8.empty()) {
            zodziu_pasikartojimas[lower_utf8]++;
        }
    }

    ofstream fr("rezultatas.txt");
    for (auto it = zodziu_pasikartojimas.begin(); it != zodziu_pasikartojimas.end(); ++it) {
        fr << it->first << ": " << it->second << endl;
    }
}