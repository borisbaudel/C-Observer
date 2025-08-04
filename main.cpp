#include <iostream> // Inclut la bibliothèque iostream pour les opérations d'entrée/sortie
#include "Subject.h"// Inclut l'en-tête de la classe de base 'Subject'
#include "SubjectImpl.h" // Inclut l'en-tête de la classe 'SubjectImpl'
#include "ObserverImpl.h" // Inclut l'en-tête de la classe 'ObserverImpl'

// Définit une fonction pour tester la fonctionnalité de 'SubjectImpl'
void testSubjectFunctionality() {
    std::cout << "=== Test Subject Functionality ===" << std::endl;
    // Affiche un titre pour cette section de test

    SubjectImpl subject;
    // Crée une instance de 'SubjectImpl'

    std::cout << "Initial value: " << subject.getValue() << std::endl;
    // Affiche la valeur initiale du sujet

    subject.setValue("New Value");
    // Modifie la valeur du sujet

    std::cout << "Updated value: " << subject.getValue() << std::endl;
    // Affiche la valeur mise à jour du sujet
}

// Définit une fonction pour tester le mécanisme d'observation
void testObserverMechanism() {
    std::cout << "\n=== Test Observer Mechanism ===" << std::endl;
    // Affiche un titre pour cette section de test

    SubjectImpl subject;
    // Crée une instance de 'SubjectImpl'

    ObserverImpl observer1, observer2;
    // Crée deux instances de 'ObserverImpl'

    subject.registerObserver(&observer1);
    subject.registerObserver(&observer2);
    // Enregistre les observateurs auprès du sujet

    subject.setValue("Notify Observers");
    // Met à jour la valeur du sujet, ce qui déclenche la notification des observateurs

    subject.unregisterObserver(&observer2);
    // Désenregistre le deuxième observateur

    subject.setValue("Second Update");
    // Met à jour la valeur du sujet une deuxième fois
}

// Définit une fonction pour tester un scénario global avec plusieurs sujets et observateurs
void testGlobalScenario() {
    std::cout << "\n=== Test Global Scenario ===" << std::endl;
    // Affiche un titre pour cette section de test

    SubjectImpl fruitSubject, countrySubject, sportSubject;
    // Crée trois sujets différents

    ObserverImpl observerA, observerB, observerC;
    // Crée trois observateurs différents

    fruitSubject.registerObserver(&observerA);
    countrySubject.registerObserver(&observerB);
    sportSubject.registerObserver(&observerC);
    // Enregistre différents observateurs pour chaque sujet

    fruitSubject.setValue("Banana");
    countrySubject.setValue("Germany");
    sportSubject.setValue("Rugby");
    // Met à jour les valeurs de chaque sujet

    sportSubject.setValue("Tennis");
    countrySubject.unregisterObserver(&observerB);
    countrySubject.setValue("France");
    // Fait d'autres mises à jour et modifie les enregistrements des observateurs
}

// Point d'entrée du programme
int main() {
    std::cout << "Observer Pattern Tests Begin" << std::endl;
    std::cout << "========================================" << std::endl;
    // Affiche un en-tête pour le début des tests

    // Appelle les fonctions de test
    testSubjectFunctionality();
    testObserverMechanism();
    testGlobalScenario();

    std::cout << "\nTests Completed" << std::endl;
    // Affiche un message indiquant la fin des tests
    return 0;
    // Renvoie 0 pour indiquer que le programme s'est terminé avec succès
}
