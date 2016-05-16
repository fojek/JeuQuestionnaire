# JeuQuestionnaire
Jeu questionnaire pour le camp

A Faire :
 - [x] Fabriquer quatre boutons;
 - [x] Fabriquer un boitier;
 - [ ] Imprimer une etiquette (facultatif);
 - [x] Terminer le programme, verifier le delais;
 - [x] Configurer un nouveau Pi avec le logiciel;
 - [x] Test final avant remise.

2016-01-05 - La version en ligne compile. Pour samedi prochain, je dois completer le logiciel et le hardware. Pour les boutons, j'ai achete une tige de bois; je pourrai en couper des bouts d'environ 4 pouces, les percer et puis y faire passer le fil. Le fil donne par fr Francois-Xavier ne fonctionne pas, il est trop mince. Je vais voir si je peux trouver du cable reseau qui ferait l'affaire. Pour le logiciel, je dois verifier le temps de reaction, car aux derniers tests il semblait qu'il y avait parfois un petit delais. C'est peut-etre lie au mecanisme du bouton (le bleu, je crois) qui fonctionne mal. Je devrai commander un remplacement. Je dois aussi trouver un boitier pour le Pi. Pour le moment, je n'ai pas d'idee, mais je pourrai peut-etre ramasser quelque chose au travail, a suivre. 

2016-01-06 - J'ai fait un prototype de bouton de 3" de long, avec un câble réseau. Je prends un rondin de 1" de diamètre, 3" de long, et je perce un trou de 5/8" à une extrémité (pour le bouton), puis bord-en-bord avec une mèche 3/8" (pour le fil). Colle chaude pour solidifier le fil. Le résultat est plutôt bon, attention le bois tend à fendiller - je pourrai le coller au pire. Suite au prototype, je ferai le produit fini d'une longueur de 4", et puis avec un trou de 1/4" pour le fil. J'utiliserai peut-être du silicone à la place de la colle chaude. Avant d'installer le bouton et le fil, je teindrai et vernirai les goujons. Aujourd'hui, je dois trouver un boîtier, le fil, et faire les goujons. 

2016-01-06 - J'ai trouve un boitier qui fait 7x10x4". C'est gros, mais ca va laisser de la place pour faire un montage correct. Il y a deja les trous pour les passe-fils, j'en mettrai deux pour les boutons je laisserai un trou vide pour le "KVM". J'ai aussi trouve du fil, c'est du 2c20 je crois, il est deja coupe en longueurs d'environ 3 metres. J'ai coupe, perce et verni 4 goujons de bois, demain je vais souder les fils et peut-etre faire une 2e couche.

2016-01-10 - Version fonctionnelle, 1.0. Note : pour rendre le fichier sur le bureau executable, faire :

``sudo chown root test.sh`` Pour donner la propriete a root
``sudo chmod +s test.sh`` Pour executer en tant que owner root.
