#include "headers.h"

int main() {
    std::setlocale(LC_ALL, "");
    std::map<std::string, std::vector<int>> zodziu_pasikartojimas;
    std::set<string> rastos_nuorodos;
    std::string zodis;
    std::ifstream fd("tekstas.txt");
    std::stringstream ss;
    ss << fd.rdbuf();
    fd.close();

    int eilute = 1;
    string linija;

    while (std::getline(ss, linija)) {
        std::istringstream iss(linija);
        string zodis;
        std::regex url_regex(R"(https?://[^\s]+)", std::regex::icase);
        while (iss >> zodis) {
            if (std::regex_match(zodis, url_regex)) {
                while (zodis.back() == '.' || zodis.back() == ',' || zodis.back() == '?' || zodis.back() == '!' || zodis.back() == ';') {
                    zodis.pop_back();
                }
                rastos_nuorodos.insert(zodis);
                continue;
            }

            icu::UnicodeString ustr = icu::UnicodeString::fromUTF8(zodis);

            icu::UnicodeString cleaned;
            for (int32_t i = 0; i < ustr.length(); ++i) {
                UChar32 c = ustr.char32At(i);
                if (u_isalpha(c)) {
                    cleaned.append(c);
                }
                if (U_IS_SUPPLEMENTARY(c)) {
                    ++i;
                }
            }

            cleaned.toLower();

            std::string lower_utf8;
            cleaned.toUTF8String(lower_utf8);

            if (!lower_utf8.empty()) {
                zodziu_pasikartojimas[lower_utf8].push_back(eilute);
            }
        }
        eilute++;
    }

    ofstream fr("rezultatas.txt");
    for (auto it = zodziu_pasikartojimas.begin(); it != zodziu_pasikartojimas.end(); ++it) {
        fr << it->first << " (" << it->second.size() <<"): ";
        for (auto x : it->second) {
            fr << x << " ";
        }
        fr << endl;
    }

    ofstream nrd("nuorodos.txt");
    for (auto x : rastos_nuorodos) {
        nrd << x << endl;
    }
}