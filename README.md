# 🧰 Naudojimosi instrukcijos

1. Nusiklonuokite repozitoriją;
2. Eikite į Powershell su administratoriaus teisėmis ir į pasirinktą aplanką (pavyzdžiui C:/dev/vpckg) instaliuokite vpckg su komanda `git clone https://github.com/microsoft/vcpkg.git` (jeigu jo neturite);
3. Iš eilės paleiskite šias komandas `cd vcpkg`, `.\bootstrap-vcpkg.bat`, `.\vcpkg integrate install`, `.\vcpkg install icu`. Šis žingsnis reikalingas, kad būtų palaikomi ne ASCII simboliai (pavyzdžiui lietuviškos, skandinaviškos raidės);
4. Atsidarykite projektą per Visual Studio;
5. Susikurkite failą *tekstas.txt*, į kurį įveskite savo norimą tikrinti tekstą;
6. Paleiskite kodą;
7. Rezultatus matysite faile *rezultatai.txt* – išvardinti žodžiai, jų dažnis ir eilutė tekste – bei *nuorodos.txt* – išvardintos tekste rastos nuorodos.
