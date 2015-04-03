#include <memory>
#include "CABS\Actor.h"
#include "CABS\ActorManager.h"
#include "CABS\Component.h"
#include "CABS\DrawableComponent.h"
#include "CABS\AudibleComponent.h"
#include "CABS\TransformableComponent.h"
#include "CABS\DrawingSystem.h"
#include "CABS\AudioSystem.h"


int main(int argc, char** argv)
{
    sf::RenderWindow mainWindow;

    mainWindow.create(sf::VideoMode(800, 400, 32), "Component Programming Test", sf::Style::Titlebar);
    mainWindow.setFramerateLimit(60);

    ActorManager actorManager;

    // Criando o ator e seus componentes.
    int testActor_1_ID = actorManager.CreateActor("TestActor1");
    DrawableComponent* drawableComponent = new DrawableComponent();
    drawableComponent->Init("resources/red_bitty.png");
    TransformableComponent* transformableComponent = new TransformableComponent();
    transformableComponent->SetPosition(400, 200);
    transformableComponent->SetRotation(45.0f);
    transformableComponent->SetScale(1.5f, 1.5f);
    AudibleComponent* audibleComponent = new AudibleComponent();
    audibleComponent->Init("resources/sound.wav");
    audibleComponent->SetLoop(true);

    // Adicionando os componentes do ator ao ator.
    ActorSharedPointer pActor = actorManager.GetActor(testActor_1_ID);
    pActor->AddComponent(drawableComponent);
    pActor->AddComponent(audibleComponent);
    pActor->AddComponent(transformableComponent);
    
    DrawingSystem drawingSystem(mainWindow);
    drawingSystem.AddActor(pActor);

    AudioSystem audioSystem;    
    audioSystem.AddActor(pActor);

    audioSystem.PlayAll();

    mainWindow.clear(sf::Color(0, 0, 0));
    drawingSystem.DrawAll();
    mainWindow.display();

    sf::sleep(sf::seconds(2.5f));
    
    audioSystem.StopAll();

    // Fim do Programa
    mainWindow.close();
    return 0;
}
