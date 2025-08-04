#pragma once  // Prévient les inclusions multiples du même fichier d'en-tête
#include "Subject.h" // Inclut l'en-tête de la classe 'Subject', nécessaire pour la référence à 'Subject' dans la classe 'Observer'
class Subject; // Déclaration anticipée de la classe 'Subject' pour indiquer son existence avant son utilisation complète

class Observer {
public:
    // Section publique de la classe Observer

    Observer(){}; 
    // Constructeur par défaut de la classe Observer
    // Il ne fait rien de spécial dans ce cas

    virtual ~Observer(){}; 
    // Destructeur virtuel de la classe Observer
    // Important pour une classe destinée à être héritée, permettant une destruction propre des sous-classes

    virtual void update(Subject* s) = 0;
    // Méthode virtuelle pure 'update', qui doit être implémentée par les sous-classes
    // Prend un pointeur vers un 'Subject' en tant que paramètre
    // Cette méthode est destinée à être appelée pour notifier l'observateur d'un changement dans le sujet
};



