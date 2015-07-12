module.exports = {
  js: {
    files: ['js/src/**/*.js'],
    tasks: ['uglify:build'],
    options: {
      livereload: true
    }
  },
  css: {
    files: ['sass/**/*.scss'],
    tasks: ['compass:build'],
    options: {
      livereload: true
    }
  },
  images: {
    files: ['images/src/**/*.jpg', 'images/src/**/*.png'],
    tasks: 'imagemin:build'
  }
}