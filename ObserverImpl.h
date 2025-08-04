#pragma once// Prévient les inclusions multiples du même fichier d'en-tête
#include <string>// Inclut la bibliothèque standard des chaînes de caractères pour une utilisation éventuelle dans la classe
#include "Observer.h"// Inclut l'en-tête de la classe de base 'Observer'

class ObserverImpl : public Observer {
// Déclare la classe 'ObserverImpl' qui hérite de 'Observer'

public:
    // Déclaration des méthodes publiques

    ObserverImpl(); 
    // Constructeur par défaut de la classe ObserverImpl

    virtual ~ObserverImpl() override; 
    // Destructeur virtuel de la classe ObserverImpl
    // Le mot-clé 'override' indique que cette méthode remplace une méthode virtuelle de la classe de base

    void update(Subject* s) override;
    // Méthode pour mettre à jour l'état de l'observateur
    // 's' est un pointeur vers le sujet observé
    // 'override' indique que cette méthode remplace une méthode virtuelle de la classe de base
};
