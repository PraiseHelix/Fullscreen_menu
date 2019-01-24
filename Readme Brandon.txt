de belangrijkste classen zijn:
- menu_screen
- text_option (indirect subklasse van sf::Text)

Als eerste vergeet het font niet!

Hoe het nu werkt is dat je een menu_screen aanmaakt.
dan de text_options als shared pointers
de text_option pointers voeg je dan aan menu_screen toe doormiddel van de add() functie

en dat is het heel basis.

Verder:
- text_option is een subclasse van menu_option wat een abstracte subklasse is van sf::Text
- op elk menu_screen is een van de menu_options geselecteerd. wat geselecteerd is wordt bijgehouden door de index van die optie in de vector
- er is al een kleine test van een Framerate optie. Ik wou dit eerst ontwijken door maar 1 classe te hebben voor elk soort optie dankzij lambda's. Maar dat kreeg ik niet goed werkend..

Als er iets verbeterd moet worden hoor ik het wel. ik heb natuurlijk een beetje gegokt hoe jij dingen wilt hebben.


