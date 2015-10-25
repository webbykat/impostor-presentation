var gulp        = require('gulp'),
    compass     = require('gulp-compass'),
    pngquant   = require('imagemin-pngquant'),
    optipng    = require('imagemin-optipng'),
    jpegoptim  = require('imagemin-jpegoptim'),
    svgo       = require('imagemin-svgo'),
    debug      = require('gulp-debug');

// Sass
gulp.task('compass', function() {
  gulp.src('sass/*.scss')
    .pipe(compass({
      config_file: 'config.rb',
      css: 'css',
      sass: 'sass',
      bundle_exec: true
    }))
    .pipe(gulp.dest('css'));
});

// Images
gulp.task('images', function () {
    gulp.src('images/src/**/*.{png,jpg,jpeg,gif,svg}')
        .pipe(debug({title: 'optimized images:'}))
        .pipe(pngquant({quality: '65-80', speed: 4})())
        .pipe(optipng({optimizationLevel: 3})())
        .pipe(jpegoptim({max: 70})())
        .pipe(svgo()())
        .pipe(gulp.dest('images/build'));
});

// This defines the default task, which is the task or tasks run when you enter `gulp` alone on the command line.
gulp.task('default', ['compass']);