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
- Une fois dans le dossier Client `cmake .` pour génerer le makefile
- Aller dans le dossier cmake `cd cmake-build-debug`
- Compiler le programme `make`
- Lancer le Client `./Client` 

