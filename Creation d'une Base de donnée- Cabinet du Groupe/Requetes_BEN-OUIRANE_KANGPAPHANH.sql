-- Affiche les patients qui fêtent leur anniversaire aujourd'hui,
SELECT IdPatient, NomPatient, PrenomPatient
FROM PATIENT
WHERE strftime('%m-%d', DateNaissPatient) = strftime('%m-%d', 'now');
-- Utile pour les souhaits d'anniversaire (Bien-être des patients)

-- Affiche les secrétaires qui fêtent leur anniversaire aujourd'hui.
SELECT IdSecretaire, NomSecretaire, PrenomSecretaire
FROM SECRETAIRE
WHERE strftime('%m-%d', DateNaissSecr) = strftime('%m-%d', 'now');
-- Utile pour les souhaits d'anniversaire (Bien-être des employés)

-- Affiche les noms des patients ayant une visite à une date précise,
SELECT P.IdPatient, NomPatient, PrenomPatient
FROM PATIENT P
INNER JOIN VISITE_PATIENT V ON P.IdPatient = V.IdPatient
WHERE V.DateVisite = '2024-01-14';
-- Utile pour la planification des rendez-vous.

-- Donne la moyenne d'âge des patients enregistrés dans la base,
SELECT AVG(strftime('%Y', 'now') - strftime('%Y', DateNaissPatient)) AS MoyenneAge
FROM PATIENT;
-- Utile pour une vue d'ensemble démographique (statistiques).

-- Affiche le nombre de visites par mois pour une année spécifique,
SELECT strftime('%m', DateVisite) AS Mois, COUNT(*) AS NombreVisites
FROM VISITE_PATIENT
WHERE strftime('%Y', DateVisite) = '2024'
GROUP BY strftime('%m', DateVisite);
-- Utile pour l'analyse temporelle.

-- Donne les contrats d'infirmiers actifs à la date actuelle,
SELECT *
FROM CONTRATINFIRMIER
WHERE DateDebutCont <= DATE('now') AND DateFinCont >= DATE('now');
-- Utile pour la gestion des ressources humaines.

-- Affiche les visites effectuées pour un patient spécifique avec leur motif.
SELECT V.IdPatient, DateVisite, MotifVisite
FROM VISITE_PATIENT V
INNER JOIN PATIENT P ON V.IdPatient = P.IdPatient
WHERE P.IdPatient = 1; -- On peut remplacer 1 par l'ID du patient spécifique
-- Utile pour les diagnostics du médecin.

-- Affiche le nom et le numéro de téléphone des médecins dans une spécialité spécifique.
SELECT M.NomMedecin, M.PrenomMedecin, M.NumTelMed
FROM MEDECIN M
WHERE M.SpecialiteMedecin = 'Cardiologie'; -- Remplacer 'Cardiologie' par la spécialité recherchée
-- Utile pour aider les patients ou pour la communication entre les médecins.

-- Affiche les infirmiers avec leur médecin superviseur et les détails de leur contrat.
SELECT I.IdInfirmier, NomInfirmier, PrenomInfirmier, NomMedecin AS MedecinSuperviseur, C.TypeCont, C.Salaire
FROM INFIRMIER I
INNER JOIN MEDECIN M ON I.IdMedecin = M.IdMedecin
INNER JOIN CONTRATINFIRMIER C ON I.IdInfirmier = C.IdInfirmier;
-- Utile pour le directeur du cabinet.

-- Afficher le nombre de visites qu'a eu un médecin aujourd’hui
SELECT COUNT(*) as totalVisitesDupuis 
FROM VISITE_PATIENT VP
INNER JOIN MEDECIN M 
ON VP.idMedecin = M.idMedecin
WHERE dateVisite = CURRENT_DATE
AND nomMedecin = 'Dupuis'; -- Remplacer le nom par le médecin recherché
-- utile pour l’analyse temporelle

-- Afficher le médecin qui a reçu le plus de patients durant l’année 2023.
SELECT M.idMedecin, nomMedecin, COUNT(idVisite) as totalVisites2023
FROM MEDECIN M
INNER JOIN VISITE_PATIENT VP 
ON M.idMedecin = VP.idMedecin
WHERE strftime('%Y', DateVisite) = '2023'
GROUP BY M.idMedecin, nomMedecin
ORDER BY totalVisites2023 DESC
LIMIT 1;
-- utile pour les statistiques

-- Afficher les bureaux non occupés
SELECT numBureau, nomBureau
FROM BUREAU
WHERE EstOccupe = 'N';
-- utile pour assigner des nouveaux médecins dans les bureaux inoccupés
-- ou voir quels bureaux n'ont pas besoin d'être nettoyés 

-- Afficher le médicament le plus prescrit aux patients selon leur maladie
SELECT ordonnance, motifVisite, COUNT(*) AS nbprescriptions
FROM VISITE_PATIENT
GROUP BY ordonnance, motifVisite
ORDER BY nbprescriptions DESC
LIMIT 1;
-- utile pour les statistiques

-- Afficher les aides ménagères et les bureaux auxquels elles sont assignées
SELECT AM.idMenagere, nomMenagere, prenomMenagere, numBureau, nomBureau
FROM AIDEMENAGERE AM
INNER JOIN BUREAU B
ON B.idMenagere = AM.idMenagere
ORDER BY AM.idMenagere;
-- utile pour le directeur du cabinet

-- Afficher les infirmiers qui travaillent avec un médecin avec une certaine spécialité
SELECT I.IdInfirmier, NomInfirmier, PrenomInfirmier, M.IdMedecin, nomMedecin, prenomMedecin
FROM INFIRMIER I
INNER JOIN MEDECIN M ON I.IdMedecin = M.IdMedecin
WHERE SpecialiteMedecin = 'Dermatologue';
-- Utile pour la gestion des infirmiers

-- Afficher les infirmiers qui travaillent avec un médecin avec une certaine spécialité
SELECT I.IdInfirmier, NomInfirmier, PrenomInfirmier, M.IdMedecin, nomMedecin, prenomMedecin
FROM INFIRMIER I
INNER JOIN MEDECIN M ON I.IdMedecin = M.IdMedecin
WHERE SpecialiteMedecin = 'Dermatologue';
-- Utile pour la gestion des infirmiers

-- Afficher le médecin qui travaille avec le plus d'infirmier
SELECT M.IdMedecin, nomMedecin, prenomMedecin, COUNT(*) as nbinfirmiers
FROM INFIRMIER I
INNER JOIN MEDECIN M ON I.IdMedecin = M.IdMedecin
GROUP BY M.IdMedecin, nomMedecin, prenomMedecin
ORDER BY nbinfirmiers DESC
LIMIT 1;
-- Utile pour la gestion des infirmiers 



