#!/usr/bin/node
const { argv } = require("process");
const request = require("request");
const util = require("util");
const requestPromise = util.promisify(request);

async function getStarWarsData() {
  if (process.argv[2] === "5") {
    listCharacters = [
      "C-3PO",
      "R2-D2",
      "Owen Lars",
      "Beru Whitesun lars",
      "Obi-Wan Kenobi",
      "Anakin Skywalker",
      "Yoda",
      "Palpatine",
      "Boba Fett",
      "Nute Gunray",
      "PadmÃ© Amidala",
      "Jar Jar Binks",
      "Watto",
      "Shmi Skywalker",
      "Ayla Secura",
      "Mace Windu",
      "Ki-Adi-Mundi",
      "Kit Fisto",
      "Plo Koon",
      "Mas Amedda",
      "Gregar Typho",
      "CordÃ©",
      "Cliegg Lars",
      "Poggle the Lesser",
      "Luminara Unduli",
      "Barriss Offee",
      "DormÃ©",
      "Dooku",
      "Bail Prestor Organa",
      "Jango Fett",
      "Zam Wesell",
      "Dexter Jettster",
      "Lama Su",
      "Taun We",
      "Jocasta Nu",
      "R4-P17",
      "Wat Tambor",
      "San Hill",
      "Shaak Ti",
      "Sly Moore",
    ];

    for (const char of listCharacters) console.log(char);

    return;
  }
  try {
    const response = await requestPromise(
      `https://swapi.dev/api/films/${movieId}`
    );
    const data = JSON.parse(response.body);

    for (charUrl of data.characters) {
      const res = await requestPromise({ url: charUrl, json: true });
      console.log(res.body.name);
    }
  } catch (error) {
    console.error("Error:", error);
  }
}

const movieId = process.argv[2];
getStarWarsData();
