# 🧰 Naudojimosi instrukcijos

1. Nusiklonuokite repozitoriją;
2. Jeigu neturite, atsiųskite [git](https://git-scm.com/downloads);
3. Jeigu neturite vpckg: eikite į Powershell su administratoriaus teisėmis ir į pasirinktą aplanką (pavyzdžiui C:/dev/vpckg) instaliuokite vpckg su komanda `git clone https://github.com/microsoft/vcpkg.git`;
4. Iš eilės paleiskite šias komandas `cd vcpkg`, `.\bootstrap-vcpkg.bat`, `.\vcpkg integrate install`, `.\vcpkg install icu`. Šis žingsnis reikalingas, kad būtų palaikomi ne ASCII simboliai (pavyzdžiui lietuviškos, skandinaviškos raidės);
5. Atsidarykite projektą per Visual Studio;
6. Susikurkite failą *tekstas.txt*, į kurį įveskite savo norimą tikrinti tekstą;
7. Paleiskite kodą;
8. Rezultatus matysite faile *rezultatai.txt* – išvardinti žodžiai, jų dažnis ir eilutė tekste – bei *nuorodos.txt* – išvardintos tekste rastos nuorodos.
