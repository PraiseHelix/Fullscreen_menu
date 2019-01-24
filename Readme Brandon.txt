de belangrijkste classen zijn:
- menu_screen
- text_option (indirect subklasse van sf::Text)

Als eerste vergeet het font niet!
Als tekst om de een of andere manier niet opkomt kan het zijn dat het het font (.ttf) bestand niet vind.

Hoe het nu werkt is dat je een menu_screen aanmaakt.
dan de text_options als shared pointers
de text_option pointers voeg je dan aan menu_screen toe doormiddel van de add() functie

en dat is het heel basis.

Verder:
- text_option is een subclasse van sf::Text.
- op elk menu_screen is een van de text_options geselecteerd. wat geselecteerd is wordt bijgehouden door de index van de optie in de vector
- Als je een lambda (std::function<void()>) wil hebben die zichzelf moet capturen. is daar de set_lambda(std::function<void()>) functie voor. zie de framerate_limit optie!

Wat werkt:
- redelijk makkelijk nieuwe opties toevoegen en aanpassen.
- in mijn 'demo' kan je met de pijltjes toetsen scrollen en met de muis opties aanklikken, Enter is ook activeren.

Als er iets verbeterd moet worden hoor ik het wel. ik heb natuurlijk een beetje gegokt hoe jij dingen wilt hebben.


