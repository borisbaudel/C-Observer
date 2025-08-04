#pragma once        
#include <string>
#include <list>

class Observer;

class Subject {
public:
    // Constructeur par défaut
    Subject() {};

    // Destructeur virtuel
    virtual ~Subject() {};

    // Récupère la valeur actuelle du sujet
    virtual std::string getValue() = 0;

    // Définit la valeur du sujet
    virtual void setValue(const std::string &value) = 0;

    // Enregistre un observateur, s'il n'est pas déjà enregistré
    virtual void registerObserver(Observer* observer) = 0;

    // Désenregistre un observateur, s'il est enregistré
    virtual void unregisterObserver(Observer* observer) = 0;

    // Vérifie si un observateur est enregistré
    virtual bool isRegisteredObserver(Observer* observer) = 0;

private:
    // Longueur ou autre propriété (non utilisée dans cet exemple)
    int length;
};
