module.exports = {
  allFiles: [
    'sass/**/*.scss'
  ],
  options: {
    bundleExec: true,
    config: '.scss-lint.yml',
    colorizeOutput: true,
    force: true
  }
}