PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE Specjalizacja (
    specjalizacjaID INT PRIMARY KEY,
    nazwaSpecjalizacji VARCHAR(255) NOT NULL
);
INSERT INTO Specjalizacja VALUES(1,'Chirurgia');
INSERT INTO Specjalizacja VALUES(2,'Dermatologia');
INSERT INTO Specjalizacja VALUES(3,'Kardiologia');
CREATE TABLE SpecjalizacjaLekarza (
    lekarzID INT,
    specjalizacjaID INT,
    FOREIGN KEY (lekarzID) REFERENCES Lekarz(lekarzID),
    FOREIGN KEY (specjalizacjaID) REFERENCES Specjalizacja(specjalizacjaID),
    PRIMARY KEY (lekarzID, specjalizacjaID)
);
INSERT INTO SpecjalizacjaLekarza VALUES(1,1);
INSERT INTO SpecjalizacjaLekarza VALUES(1,2);
INSERT INTO SpecjalizacjaLekarza VALUES(2,2);
INSERT INTO SpecjalizacjaLekarza VALUES(3,3);
CREATE TABLE Lekarz (
    lekarzID INT PRIMARY KEY,
    imieLekarza VARCHAR(255) NOT NULL,
    nazwiskoLekarza VARCHAR(255) NOT NULL,
    rokZatrudnienia INT NOT NULL
);
INSERT INTO Lekarz VALUES(1,'Jan','Kowalski',2010);
INSERT INTO Lekarz VALUES(2,'Anna','Nowak',2015);
INSERT INTO Lekarz VALUES(3,'Marek','Wójcik',2018);
INSERT INTO Lekarz VALUES(4,'Andrzej','Mozgawa',2024);
CREATE TABLE Pacjent (
    pacjentID INT PRIMARY KEY,
    imie VARCHAR(255) NOT NULL,
    nazwisko VARCHAR(255) NOT NULL,
    pesel VARCHAR(11) NOT NULL,
    email VARCHAR(255) NOT NULL,
    lekarzID INT,
    FOREIGN KEY (lekarzID) REFERENCES Lekarz(lekarzID)
);
INSERT INTO Pacjent VALUES(1,'Adam','Nowak','12345678901','adam@example.com',1);
INSERT INTO Pacjent VALUES(2,'Ewa','Kowalska','23456789012','ewa@example.com',2);
INSERT INTO Pacjent VALUES(3,'Piotr','Zając','34567890123','piotr@example.com',3);
CREATE TABLE Recepta (
    receptaID INT PRIMARY KEY,
    pacjentID INT,
    lekarzID INT,
    FOREIGN KEY (pacjentID) REFERENCES Pacjent(pacjentID),
    FOREIGN KEY (lekarzID) REFERENCES Lekarz(lekarzID)
);
INSERT INTO Recepta VALUES(1,1,1);
INSERT INTO Recepta VALUES(2,2,2);
INSERT INTO Recepta VALUES(3,3,3);
INSERT INTO Recepta VALUES(4,2,1);
CREATE TABLE ZawartoscRecepty (
    receptaID INT,
    lekID INT,
    dawkaNaDzien INT,
    opakowanLeku INT,
    FOREIGN KEY (receptaID) REFERENCES Recepta(receptaID),
    FOREIGN KEY (lekID) REFERENCES Lek(lekID),
    PRIMARY KEY (receptaID, lekID)
);
INSERT INTO ZawartoscRecepty VALUES(1,1,2,1);
INSERT INTO ZawartoscRecepty VALUES(2,2,1,2);
INSERT INTO ZawartoscRecepty VALUES(3,3,1,3);
INSERT INTO ZawartoscRecepty VALUES(1,4,10,2);
CREATE TABLE Lek (
    lekID INT PRIMARY KEY,
    nazwaLeku VARCHAR(255) NOT NULL,
    tabletekwOpakowaniu INT NOT NULL,
    grupaLekowID INT,
    FOREIGN KEY (grupaLekowID) REFERENCES GrupaLekow(grupaLekowID)
);
INSERT INTO Lek VALUES(1,'Paracetamol',20,1);
INSERT INTO Lek VALUES(2,'Insulina',55,2);
INSERT INTO Lek VALUES(3,'Loratadyna',10,3);
INSERT INTO Lek VALUES(4,'Tesciu',100,4);
INSERT INTO Lek VALUES(5,'TesciuMAX',100,4);
CREATE TABLE GrupaLekow (
    grupaLekowID INT PRIMARY KEY,
    nazwaGrupyLekow VARCHAR(255) NOT NULL
);
INSERT INTO GrupaLekow VALUES(1,'Przeciwbólowe');
INSERT INTO GrupaLekow VALUES(2,'Przeciwcukrzycowe');
INSERT INTO GrupaLekow VALUES(3,'Przeciwhistaminowe');
INSERT INTO GrupaLekow VALUES(4,'Sterydy');
CREATE VIEW "Sterydy" AS SELECT lekID, nazwaLeku FROM Lek l WHERE l.GrupaLekowID=(SELECT GrupaLekowID FROM GrupaLekow WHERE nazwaGrupyLekow="Sterydy");
COMMIT;
