all: main
# Cible par défaut qui dépend de la cible 'main'.
# L'exécution de 'make' sans arguments construira la cible 'main'.

CXX = clang++
# Définit la variable 'CXX' pour spécifier le compilateur C++ utilisé, ici clang++.

override CXXFLAGS += -g -Wno-everything
# Ajoute des options supplémentaires aux drapeaux du compilateur C++ (CXXFLAGS).
# '-g' : inclut des informations de débogage dans les fichiers exécutables générés.
# '-Wno-everything' : désactive tous les avertissements.

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print | sed -e 's/ /\\ /g')
# Utilise la commande 'find' pour rechercher tous les fichiers source .cpp dans le répertoire courant (et les sous-répertoires), 
# en ignorant le répertoire '.ccls-cache'.
# Utilise 'sed' pour échapper les espaces dans les noms de fichiers.

HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)
# Recherche tous les fichiers d'en-tête .h, en ignorant également le répertoire '.ccls-cache'.

main: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o "$@"
# Règle pour construire la cible 'main'.
# Compile tous les fichiers sources (.cpp) avec les fichiers d'en-tête correspondants (.h) en utilisant les drapeaux définis.
# '-o "$@"' spécifie le nom de l'exécutable à générer, ici 'main'.

main-debug: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -O0 $(SRCS) -o "$@"
# Règle pour construire la cible 'main-debug'.
# Semblable à la règle 'main', mais ajoute '-O0' pour désactiver l'optimisation, utile pour le débogage.

clean:
	rm -f main main-debug
# Règle 'clean' pour nettoyer le projet.
# Supprime les fichiers exécutables 'main' et 'main-debug'.
