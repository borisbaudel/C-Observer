#include "SubjectImpl.h"// Inclusion de l'en-tête de la classe SubjectImpl
#include "Observer.h"// Inclusion de l'en-tête de la classe Observer
#include <algorithm> // Pour std::find // Inclusion de la bibliothèque algorithm pour utiliser la fonction std::find
#include <iostream>// Inclusion de la bibliothèque iostream pour les opérations d'entrée/sortie
#include <list> // Inclusion de la bibliothèque list pour utiliser les listes
#include <string> // Inclusion de la bibliothèque string pour utiliser les chaînes de caractères
#include <typeinfo> // Inclusion de la bibliothèque typeinfo pour les informations de type

SubjectImpl::SubjectImpl() {
  std::cerr << "SubjectImpl: Nouveau sujet construit\n";
}; // Constructeur de la classe SubjectImpl qui affiche un message lors de la création

SubjectImpl::~SubjectImpl() {
  std::cerr << "SubjectImpl: Sujet détruit\n";
}; // Destructeur de la classe SubjectImpl qui affiche un message lors de la destruction

std::string SubjectImpl::getValue() {
  // Retourne l'état actuel du sujet
  return subj;
}; // Méthode pour obtenir la valeur actuelle du sujet

void SubjectImpl::setValue(const std::string &s) {
  // Met à jour l'état du sujet avec la nouvelle valeur
  subj = s;
  std::cerr << "SubjectImpl: État modifié en : " << subj << std::endl;
  // Notifie tous les observateurs enregistrés du changement
  for (auto observer : Observer_list) {
    observer->update(this);
  }
}; // Méthode pour définir la valeur du sujet et notifier les observateurs

void SubjectImpl::registerObserver(Observer *o) {
  // Vérifie si l'observateur n'est pas déjà enregistré
  if (!isRegisteredObserver(o)) {
    // Enregistre le nouvel observateur
    Observer_list.push_front(o);
    std::cout << "SubjectImpl: Nouvel observateur enregistré\n";
  } else {
    std::cout << "SubjectImpl: Observateur déjà enregistré\n";
  }
}; // Méthode pour enregistrer un nouvel observateur

void SubjectImpl::unregisterObserver(Observer *o) {
  // Vérifie si l'observateur est enregistré
  if (isRegisteredObserver(o)) {
    // Retire l'observateur de la liste
    Observer_list.remove(o);
    std::cout << "SubjectImpl: Observateur désenregistré\n";
  } else {
    std::cout << "SubjectImpl: Tentative de désenregistrement d'un observateur non enregistré\n";
  }
}; // Méthode pour désenregistrer un observateur

bool SubjectImpl::isRegisteredObserver(Observer *o) {
  // Vérifie si l'observateur est dans la liste des observateurs
  return std::find(Observer_list.begin(), Observer_list.end(), o) != Observer_list.end();
}; // Méthode pour vérifier si un observateur est enregistré
