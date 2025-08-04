#pragma once// Prévient les inclusions multiples du même fichier d'en-tête
#include <list>// Inclut la bibliothèque standard de la liste pour la gestion des listes
#include <string>// Inclut la bibliothèque standard des chaînes de caractères
#include "Subject.h"// Inclut l'en-tête de la classe de base 'Subject'
#include "Observer.h"// Inclut l'en-tête de la classe 'Observer'

class SubjectImpl : public Subject {
// Déclare la classe 'SubjectImpl' qui hérite de 'Subject'
public:
    // Déclaration des méthodes publiques

    // Constructeur par défaut
    SubjectImpl(); 

    // Destructeur virtuel
    virtual ~SubjectImpl() override; 
    // Le mot-clé 'virtual' assure que le destructeur est correct pour la polymorphie
    // 'override' signifie que cette méthode remplace une méthode virtuelle de la classe de base

    // Récupère l'état actuel du sujet
    std::string getValue() override;
    // 'override' indique que cette méthode remplace une méthode virtuelle de la classe de base

    // Met à jour l'état du sujet
    void setValue(const std::string &s) override;
    // 's' est la nouvelle valeur à attribuer à 'subj'

    // Ajoute un observateur à la liste, si non présent
    void registerObserver(Observer* o) override;
    // 'o' est le pointeur vers l'observateur à enregistrer

    // Retire un observateur de la liste, si présent
    void unregisterObserver(Observer* o) override;
    // 'o' est le pointeur vers l'observateur à désenregistrer

    // Vérifie si un observateur est enregistré
    bool isRegisteredObserver(Observer* o) override;
    // 'o' est le pointeur vers l'observateur dont on vérifie l'enregistrement
    // Retourne 'true' si l'observateur est enregistré, 'false' sinon

private:
    // Déclaration des membres privés de la classe

    std::list<Observer*> Observer_list; 
    // Liste contenant les pointeurs vers les observateurs enregistrés

    std::string subj = "subject initial"; 
    // Chaîne de caractères représentant l'état initial du sujet
};
