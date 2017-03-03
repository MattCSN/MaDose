DELETE FROM `utilisateur`;
DELETE FROM `recette`;
DELETE FROM `ingredient`;

INSERT INTO `utilisateur` (`email`,`pseudo`,`date_naissance`,`date_inscription`,`url_photo`,`presentation`) VALUES ('matt.coisnon@free.fr','MaDose','2016/09/25','2017/01/01','img/profil/madose.png','MaDose est un doseur connecté !!!');

INSERT INTO `recette` (`nom_recette`,`score`,`date_creation`,`url_image`,`description`) VALUES ('Mojito','1000','2017/03/03','img/cocktail/mojito.png','Le mojito est le cocktail le plus célèbre selon 1001 cocktail.');

INSERT INTO `ingredient` (`nom_ingredient`,`masse_vol`,`couleur`) VALUES ('eau','10','FFFFFF');
