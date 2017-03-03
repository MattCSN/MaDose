CREATE DATABASE IF NOT EXISTS ma_dose;

CREATE TABLE IF NOT EXISTS utilisateur
(
    email VARCHAR(100),
    pseudo VARCHAR(100),
    date_naissance DATE,
    date_inscription DATE,
    url_photo VARCHAR(255),
    presentation VARCHAR(160)
) ;

CREATE TABLE IF NOT EXISTS recette
(
    nom_recette VARCHAR(100),
    score INT,
    date_creation DATE,
    url_image VARCHAR(255),
    description VARCHAR(500)
) ;


CREATE TABLE IF NOT EXISTS ingredient
(
    nom_ingredient VARCHAR(50),
    masse_vol INT,
    couleur VARCHAR(6)
) ;

CREATE TABLE IF NOT EXISTS Suivre
(
	pseudo VARCHAR(100),
    pseudoSuivi VARCHAR(100)
) ;

CREATE TABLE IF NOT EXISTS Creer
(
	pseudo VARCHAR(100),
    nom_recette VARCHAR(100),
    aime INT
) ;

CREATE TABLE IF NOT EXISTS Contenir
(
	nom_recette VARCHAR(100),
    nom_ingredient VARCHAR(50),
    insctuction VARCHAR(160),
    quantité INT,
    ordre INT
) ;