#include "ObserverImpl.h"// Inclut l'en-tête de la classe ObserverImpl
#include <iostream> // Inclut la bibliothèque iostream pour les opérations d'entrée/sortie (par exemple, std::cout et std::cerr)

ObserverImpl::ObserverImpl() {
  // Constructeur de la classe ObserverImpl
  std::cerr << "New Observer constructed\n";
  // Affiche un message dans le flux d'erreurs standard lors de la construction d'un nouvel observateur
};

ObserverImpl::~ObserverImpl() {
  // Destructeur de la classe ObserverImpl
  std::cerr << "Observer destructed\n";
  // Affiche un message dans le flux d'erreurs standard lors de la destruction de l'observateur
}

void ObserverImpl::update(Subject *s) {
  // Méthode 'update' qui est appelée pour notifier l'observateur d'un changement dans le sujet
  std::cout << "Subject updated : " << s->getValue() << std::endl;
  // Affiche un message dans la sortie standard indiquant que le sujet a été mis à jour
  // 's->getValue()' appelle la méthode 'getValue' sur l'objet sujet pour obtenir sa valeur actuelle
};
