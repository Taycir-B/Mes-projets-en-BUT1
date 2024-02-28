-- Insertions dans la table PATIENT
INSERT INTO PATIENT (NomPatient, PrenomPatient, DateNaissPatient, SexePatient, NationalitePatient, AdressePatient, NumTelPatient, MailPatient, Remarque, DatePremVisite) VALUES
('Dupont', 'Alice', '1990-03-15', 'F', 'Française', '12 Rue des Lilas, Paris', '0601020304', 'alice.dupont@example.com', 'Asthme', '2023-05-20'),
('Martin', 'Louis', '1985-07-10', 'H', 'Française', '8 Avenue Victor Hugo, Lyon', '0612345678', 'louis.martin@example.com', 'Hypertension artérielle', '2023-04-18'),
('Lefevre', 'Sophie', '1992-11-22', 'F', 'Française', '25 Rue des Roses, Marseille', '0654321098', 'sophie.lefevre@example.com', 'Diabète de type 2', '2023-06-25'),
('Moreau', 'Pierre', '1980-09-05', 'H', 'Française', '3 Boulevard Carnot, Toulouse', '0609876543', 'pierre.moreau@example.com', 'Allergie au pollen', '2023-03-10'),
('Dubois', 'Camille', '1976-12-30', 'F', 'Française', '14 Avenue Pasteur, Bordeaux', '0678901234', 'camille.dubois@example.com', 'Arthrite', '2023-07-30'),
('Garcia', 'Luc', '1995-05-18', 'H', 'Française', '9 Rue des Acacias, Lille', '0643210987', 'luc.garcia@example.com', 'Migraines fréquentes', '2023-08-12'),
('Roux', 'Juliette', '1988-04-07', 'F', 'Française', '6 Rue Victor Basch, Nice', '0698765432', 'juliette.roux@example.com', 'Anémie', '2023-02-28'),
('Fournier', 'Thomas', '1998-08-25', 'H', 'Française', '18 Avenue des Fleurs, Nantes', '0678901234', 'thomas.fournier@example.com', 'Problèmes de sommeil', '2023-09-05'),
('Michel', 'Léa', '1983-06-12', 'F', 'Française', '22 Rue des Champs, Strasbourg', '0601020304', 'lea.michel@example.com', 'Troubles digestifs', '2023-01-15'),
('Leroy', 'Gabriel', '1975-10-20', 'H', 'Française', '5 Rue du Moulin, Rennes', '0612345678', 'gabriel.leroy@example.com', 'Dépression', '2023-10-22');

-- Insertion dans la table MEDECIN

INSERT INTO MEDECIN (NomMedecin, PrenomMedecin, SpecialiteMedecin, NumTelMed, AdresseMed, MailMed) VALUES

('Dupuis', 'Thomas', 'Cardiologue', '0601020304', '12 Rue des Lilas, Paris', 'thomas.dupuis@example.com'),

('Leroux', 'Julie', 'Pédiatre', '0612345678', '8 Avenue Victor Hugo, Lyon', 'julie.leroux@example.com'),

('Martin', 'Luc', 'Dermatologue', '0654321098', '25 Rue des Roses, Marseille', 'luc.martin@example.com');

-- Insertion dans la table INFIRMIER

INSERT INTO INFIRMIER (PrenomInfirmier, NomInfirmier, DateNaissInfirmier, SexeInfirmier, AdresseInfirmier, TelephoneInfirmier, MailInfirmier, IdMedecin) VALUES ('Sarah', 'Bertrand', '1987-01-25', 'F', '7 Rue des Violettes, Paris', '0654321098', 'sarah.bertrand@example.com', 1), ('Antoine', 'Girard', '1993-08-12', 'H', '4 Avenue Pasteur, Lyon', '0609876543', 'antoine.girard@example.com', 2), ('Manon', 'Lefevre', '1980-04-03', 'F', '11 Rue du Commerce, Marseille', '0643210987', 'manon.lefevre@example.com', 1), ('Nicolas', 'Durand', '1995-11-18', 'H', '9 Boulevard Voltaire, Toulouse', '0678901234', 'nicolas.durand@example.com', 3), ('Emma', 'Leroux', '1982-06-30', 'F', '2 Rue des Lilas, Bordeaux', '0612345678', 'emma.leroux@example.com', 2), ('Maxime', 'Thomas', '1979-12-15', 'H', '5 Avenue Victor Hugo, Lille', '0601020304', 'maxime.thomas@example.com', 3), ('Julie', 'Petit', '1990-07-22', 'F', '6 Rue des Roses, Nice', '0698765432', 'julie.petit@example.com', 1), ('Lucas', 'Robin', '1986-09-08', 'H', '3 Boulevard Carnot, Nantes', '0654321098', 'lucas.robin@example.com', 2), ('Chloé', 'Dubois', '1996-03-20', 'F', '8 Rue Victor Basch, Strasbourg', '0643210987', 'chloe.dubois@example.com', 3), ('Hugo', 'Moreau', '1981-05-10', 'H', '12 Avenue des Fleurs, Rennes', '0609876543', 'hugo.moreau@example.com', 1);

-- Insertion dans la table CONTRATINFIRMIER
INSERT INTO CONTRATINFIRMIER (TypeCont, DateDebutCont, DateFinCont, Salaire, IdInfirmier) VALUES
('CDI', '2023-01-01', '2023-12-31', 2500.00, 1),
('CDD', '2023-02-15', '2023-08-14', 2100.00, 2),
('CDI', '2023-03-20', '2024-03-19', 2700.00, 3),
('CDD', '2023-04-10', '2023-10-09', 2300.00, 4),
('CDI', '2023-05-05', '2024-05-04', 2600.00, 5),
('CDD', '2023-06-18', '2023-12-17', 2200.00, 6),
('CDI', '2023-07-30', '2024-07-29', 2800.00, 7),
('CDD', '2023-08-25', '2024-02-24', 2400.00, 8),
('CDI', '2023-09-12', '2024-09-11', 2900.00, 9),
('CDD', '2023-10-08', '2024-04-07', 2500.00, 10);

-- Insertion dans la table SECRETAIRE

INSERT INTO SECRETAIRE (PrenomSecretaire, NomSecretaire, DateNaissSecr, SexeSecr, NumTelSecr, AdresseSecr, MailSecr, IdMedecin) VALUES ('Manon', 'Lefevre', '1980-04-03', 'F', '0654321098', '11 Rue du Commerce, Marseille', 'manon.lefevre@example.com', 1), ('Nicolas', 'Durand', '1995-11-18', 'H', '0678901234', '9 Boulevard Voltaire, Toulouse', 'nicolas.durand@example.com', 2), ('Emma', 'Leroux', '1982-06-30', 'F', '0612345678', '2 Rue des Lilas, Bordeaux', 'emma.leroux@example.com', 3), ('Maxime', 'Thomas', '1979-12-15', 'H', '0601020304', '5 Avenue Victor Hugo, Lille', 'maxime.thomas@example.com', 1), ('Julie', 'Petit', '1990-07-22', 'F', '0698765432', '6 Rue des Roses, Nice', 'julie.petit@example.com', 2), ('Lucas', 'Robin', '1986-09-08', 'H', '0654321098', '3 Boulevard Carnot, Nantes', 'lucas.robin@example.com', 3), ('Chloé', 'Dubois', '1996-03-20', 'F', '0643210987', '8 Rue Victor Basch, Strasbourg', 'chloe.dubois@example.com', 1), ('Hugo', 'Moreau', '1981-05-10', 'H', '0609876543', '12 Avenue des Fleurs, Rennes', 'hugo.moreau@example.com', 2), ('Sarah', 'Bertrand', '1987-01-25', 'F', '0654321098', '7 Rue des Violettes, Paris', 'sarah.bertrand@example.com', 3), ('Antoine', 'Girard', '1993-08-12', 'H', '0609876543', '4 Avenue Pasteur, Lyon', 'antoine.girard@example.com', 1);

-- Insertion dans la table VISITE_PATIENT

INSERT INTO VISITE_PATIENT (DateVisite, MotifVisite, Ordonnance, Certificat, NotesMedicales, Honoraire, IdPatient, IdMedecin) VALUES

('2023-01-15', 'Examen de routine', 'Paracétamol', NULL, 'Patient en bonne santé générale', 50.00, 1, 1), ('2023-02-18', 'Douleurs abdominales', 'Ranitidine', NULL, 'Repos recommandé', 60.00, 2, 2), ('2023-03-25', 'Suivi de diabète', 'Insuline', NULL, "Amélioration de l'état du patient", 70.00, 3, 3), ('2023-04-30', 'Allergie saisonnière', 'Antihistaminique', NULL, 'Prise en charge efficace', 55.00, 4, 1), ('2023-05-12', 'Problèmes articulaires', 'Anti-inflammatoire', NULL, 'Réduction des douleurs', 65.00, 5, 2), ('2023-06-28', 'Maux de tête', 'Paracétamol', NULL, 'Repos et hydratation recommandés', 45.00, 6, 3), ('2023-07-05', 'Suivi de tension artérielle', 'Bêtabloquant', NULL, 'Stabilisation des chiffres tensionnels', 75.00, 7, 1), ('2023-08-14', 'Problèmes de sommeil', 'Conseils hygiène de vie', NULL, 'Amélioration du sommeil', 55.00, 8, 2), ('2023-09-20', 'Maux de ventre', 'Antispasmodique', NULL, 'Soulagement des douleurs', 60.00, 9, 3), ('2023-10-28', 'Dépression', 'Suivi psychologique', NULL, "Stabilisation de l'humeur", 80.00, 10, 1);
-- Insertion dans la table AIDEMENAGERE

INSERT INTO AIDEMENAGERE (NomMenagere, PrenomMenagere, DateNaissMenagere, SexeMenagere, AdresseMenagere, NumTelMenagere, MailMenagere) VALUES
('Bouvier', 'Emma', '1988-02-14', 'F', '6 Rue des Violettes, Paris', '0601020304', 'emma.bouvier@example.com'),
('Legrand', 'Louis', '1977-09-20', 'H', '9 Avenue Victor Hugo, Lyon', '0612345678', 'louis.legrand@example.com'),
('Fournier', 'Chloé', '1990-06-30', 'F', '14 Rue des Roses, Marseille', '0654321098', 'chloe.fournier@example.com'),
('Morin', 'Lucas', '1985-11-18', 'H', '2 Boulevard Carnot, Toulouse', '0643210987', 'lucas.morin@example.com'),
('Girard', 'Léa', '1996-04-03', 'F', '5 Avenue Pasteur, Bordeaux', '0609876543', 'lea.girard@example.com'),
('Roux', 'Hugo', '1980-12-15', 'H', '8 Rue Victor Hugo, Lille', '0698765432', 'hugo.roux@example.com'),
('Petit', 'Juliette', '1987-07-22', 'F', '11 Rue des Lilas, Nice', '0643210987', 'juliette.petit@example.com'),
('Martin', 'Manon', '1993-09-08', 'F', '4 Boulevard Voltaire, Nantes', '0601020304', 'manon.martin@example.com'),
('Moreau', 'Antoine', '1996-03-20', 'H', '7 Rue des Roses, Strasbourg', '0678901234', 'antoine.moreau@example.com'),
('Lefevre', 'Sarah', '1981-05-10', 'F', '12 Avenue des Fleurs, Rennes', '0654321098', 'sarah.lefevre@example.com');

-- Insertion dans la table Bureau

INSERT INTO Bureau (NumBureau, NomBureau, SurfaceBureau, EstOccupe, IdMedecin, IdMenagere) VALUES

(1, 'Bureau 1', 20.5, 'O', 1, 1),

(2, 'Bureau 2', 18.2, 'N', 2, 2),

(3, 'Bureau 3', 22.0, 'O', 3, 3);