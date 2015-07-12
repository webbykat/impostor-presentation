module.exports = {
  mobile: {
    options: {
      nokey: true,
      url: "https://www.identitytheft.gov/",
      //paths: ["path1", "path2"], //use this to test an array of urls
      threshold: 80,
      locale: "en",
      strategy: "mobile"
    }
  },
  desktop: {
    options: {
      nokey: true,
      url: "https://www.identitytheft.gov/",
      //paths: ["path1", "path2"], //use this to test an array of urls
      threshold: 80,
      locale: "en",
      strategy: "desktop"
    }
  }
};