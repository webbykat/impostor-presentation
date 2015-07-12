module.exports = {
  build: {
    src: ['js/libraries/*.js','js/src/*.js'],
    dest: 'js/build/scripts.min.js',
    options: {
      sourceMap: true,
      banner: '/*! <%= grunt.template.today("yyyy-mm-dd") %> */\n'
    }
  },
  prod: {
    src: 'js/src/*.js',
    dest: 'js/build/scripts.min.js',
    options: {
      sourceMap: false
    }
  }

};