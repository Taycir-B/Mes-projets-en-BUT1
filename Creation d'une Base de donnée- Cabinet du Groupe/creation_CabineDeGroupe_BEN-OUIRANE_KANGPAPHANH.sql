-- Création de la table PATIENT
CREATE TABLE "PATIENT" (
"IdPatient"	INTEGER,
"NomPatient"	TEXT NOT NULL CHECK("NomPatient" GLOB '[a-zA-Z]*'),
"PrenomPatient"	TEXT NOT NULL CHECK("PrenomPatient" GLOB '[a-zA-Z]*'),
"DateNaissPatient"	DATE,
"SexePatient"	TEXT CHECK("SexePatient" IN ('F', 'H')),
"NationalitePatient"	TEXT CHECK("NationalitePatient" GLOB '[a-zA-Z]*'),
"AdressePatient"	TEXT,
"NumTelPatient"	TEXT NOT NULL CHECK("NumTelPatient" GLOB '[0-9]*'),
"MailPatient"	TEXT NOT NULL CHECK("MailPatient" LIKE '%@%.%'),
"Remarque"	TEXT,
"DatePremVisite"	DATE,
PRIMARY KEY("IdPatient")
);

-- Création de la table MEDECIN

CREATE TABLE "MEDECIN" ( "IdMedecin"	INTEGER, "NomMedecin"	TEXT NOT NULL CHECK("NomMedecin" GLOB '[a-zA-Z]*'), "PrenomMedecin"	TEXT NOT NULL CHECK("PrenomMedecin" GLOB '[a-zA-Z]*'), "SpecialiteMedecin"	TEXT, "NumTelMed"	TEXT NOT NULL CHECK("NumTelMed" GLOB '[0-9]**'), "AdresseMed"	TEXT, "MailMed"	TEXT NOT NULL CHECK("MailMed" LIKE '%@%.%'), PRIMARY KEY("IdMedecin") );

-- Création de la table INFIRMIER
CREATE TABLE "INFIRMIER" (
"IdInfirmier"	INTEGER,
"PrenomInfirmier"	TEXT NOT NULL CHECK("PrenomInfirmier" GLOB '[a-zA-Z]*'),
"NomInfirmier"	TEXT NOT NULL CHECK("NomInfirmier" GLOB '[a-zA-Z]*'),
"DateNaissInfirmier"	DATE,
"SexeInfirmier"	TEXT CHECK("SexeInfirmier" IN ('F', 'H')),
"AdresseInfirmier"	TEXT,
"TelephoneInfirmier"	TEXT NOT NULL CHECK("TelephoneInfirmier" GLOB '[0-9]**'),
"MailInfirmier"	TEXT NOT NULL CHECK("MailInfirmier" LIKE '%@%.%'),
"IdMedecin"	INTEGER,
PRIMARY KEY("IdInfirmier"),
FOREIGN KEY("IdMedecin") REFERENCES "MEDECIN"("IdMedecin")
);

-- Création de la table CONTRATINFIRMIER
CREATE TABLE "CONTRATINFIRMIER" (
"IdContrat"	INTEGER,
"TypeCont"	TEXT,
"DateDebutCont"	DATE,
"DateFinCont"	DATE CHECK("DateFinCont" > "DateDebutCont"),
"Salaire"	REAL CHECK("Salaire" > 0),
"IdInfirmier"	INTEGER,
PRIMARY KEY("IdContrat"),
FOREIGN KEY("IdInfirmier") REFERENCES "INFIRMIER"("IdInfirmier")
);

-- Création de la table SECRETAIRE
CREATE TABLE "SECRETAIRE" (
"IdSecretaire"	INTEGER,
"PrenomSecretaire"	TEXT NOT NULL CHECK("PrenomSecretaire" GLOB '[a-zA-Z]*'),
"NomSecretaire"	TEXT NOT NULL CHECK("NomSecretaire" GLOB '[a-zA-Z]*'),
"DateNaissSecr"	DATE,
"SexeSecr"	TEXT CHECK("SexeSecr" IN ('F', 'H')),
"NumTelSecr"	TEXT NOT NULL CHECK("NumTelSecr" GLOB '[0-9]**'),
"AdresseSecr"	TEXT,
"MailSecr"	TEXT NOT NULL CHECK("MailSecr" LIKE '%@%.%'),
"IdMedecin"	INTEGER,
FOREIGN KEY("IdMedecin") REFERENCES "MEDECIN"("IdMedecin"),
PRIMARY KEY("IdSecretaire")
);

-- Création de la table VISITE_PATIENT
CREATE TABLE "VISITE_PATIENT" (
"IdVisite"	INTEGER,
"DateVisite"	DATE,
"MotifVisite"	TEXT,
"Ordonnance"	TEXT,
"Certificat"	TEXT,
"NotesMedicales"	TEXT,
"Honoraire"	REAL CHECK("Honoraire" >= 0),
"IdPatient"	INTEGER,
"IdMedecin"	INTEGER,
FOREIGN KEY("IdPatient") REFERENCES "PATIENT"("IdPatient"),
FOREIGN KEY("IdMedecin") REFERENCES "MEDECIN"("IdMedecin"),
PRIMARY KEY("IdVisite")
);

-- Création de la table AIDEMENAGERE

CREATE TABLE "AIDEMENAGERE" ( "IdMenagere"	INTEGER, "NomMenagere"	TEXT NOT NULL CHECK("NomMenagere" GLOB '[a-zA-Z]*'), "PrenomMenagere"	TEXT NOT NULL CHECK("PrenomMenagere" GLOB '[a-zA-Z]*'), "DateNaissMenagere"	DATE, "SexeMenagere"	TEXT CHECK("SexeMenagere" IN ('F', 'H')), "AdresseMenagere"	TEXT, "NumTelMenagere"	TEXT NOT NULL CHECK("NumTelMenagere" GLOB '[0-9]**'), "MailMenagere"	TEXT NOT NULL CHECK("MailMenagere" LIKE '%@%.%'), PRIMARY KEY("IdMenagere") );

-- Création de la table Bureau
CREATE TABLE "Bureau" (
"NumBureau"	INTEGER,
"NomBureau"	TEXT,
"SurfaceBureau"	REAL CHECK("SurfaceBureau" > 0),
"EstOccupe"	TEXT CHECK("EstOccupe" IN ('O', 'N')),
"IdMedecin"	INTEGER,
"IdMenagere"	INTEGER,
FOREIGN KEY("IdMedecin") REFERENCES "MEDECIN"("IdMedecin"),
FOREIGN KEY("IdMenagere") REFERENCES "AIDEMENAGERE"("IdMenagere"),
PRIMARY KEY("NumBureau")
);
