#!/usr/bin/node
const { argv } = require("process");
const request = require("request");
const util = require("util");
const requestPromise = util.promisify(request);

async function getStarWarsData() {
  try {
    const response = await requestPromise(
      `https://swapi.dev/api/films/${movieId}`
    );
    const data = JSON.parse(response.body);
    console.log(data.characters);
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
