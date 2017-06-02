use mpicl;
DROP TABLE IF EXISTS Tracks;
DROP TABLE IF EXISTS Codes;
DROP TABLE IF EXISTS Files;
DROP TABLE IF EXISTS Users;
DROP TABLE IF EXISTS FileUsers;

CREATE TABLE Users(
user  VARCHAR(50) NOT NULL  PRIMARY KEY,
password  VARCHAR(50) NOT NULL
) ENGINE = INNODB DEFAULT CHARSET=utf8;


CREATE TABLE Files(
filename  VARCHAR(50) NOT NULL PRIMARY KEY
) ENGINE = INNODB DEFAULT CHARSET=utf8;


CREATE TABLE FilesUsers(
user  VARCHAR(50) NOT NULL,
filename  VARCHAR(50) NOT NULL,
PRIMARY KEY (user, filename), 
FOREIGN KEY (user) REFERENCES Users(user)
ON DELETE CASCADE ON UPDATE CASCADE ,
FOREIGN KEY (filename) REFERENCES Files(filename)
ON DELETE CASCADE ON UPDATE CASCADE 
) ENGINE = INNODB DEFAULT CHARSET=utf8;

CREATE TABLE Codes(
code  INT NOT NULL  PRIMARY KEY,
name  VARCHAR(50) NOT NULL,
description TEXT,
category TEXT
) ENGINE = INNODB DEFAULT CHARSET=utf8;

CREATE TABLE Tracks ( 
filename VARCHAR(50) NOT NULL,
typeRecord INT NOT NULL,
typeEvent INT NOT NULL,
time FLOAT NOT NULL,
prid INT NOT NULL,
pid INT NOT NULL,
numData INT NOT NULL,
data VARCHAR(200),
FOREIGN KEY (typeEvent) REFERENCES Codes(code) 
ON DELETE CASCADE ON UPDATE CASCADE,
FOREIGN KEY (filename) REFERENCES Files(filename) 
ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE = INNODB DEFAULT CHARSET=utf8;





