# Projet PPIL

## Testé et compilé avec :
- Java 1.8.0_312
- Cmake 3.22.2
- Make 3.81
- MacOs

### La compilation java se fait avec Maven
- Une fois dans le dossier Server `mvn clean install`
- Pour lancer `java -jar target/Server-1.0-SNAPSHOT.jar`

### La compilation c++ se fait avec cmake
- Une fois dans le dossier Client `cmake -S . -B build` pour génerer le makefile
- Aller dans le dossier cmake `cd build`
- Compiler le programme `make`
- Lancer le Client `./Client` 

## Documentations
Les documentations Client et Serveurs sont disponibles respectivements à partir de
- Client/html/index.html
- Server/doc/index.html

### Si besoin de regénerer les documentations
#### Avec doxygen
- Faire la commande `doxygen doxygen.config`
- Le fichier se trouve dans le dossier Client

