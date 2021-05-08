project('wf-decoration', ['cpp'], version: '0.0.1', license: 'Unlicense',
	default_options: ['cpp_std=c++17', 'warning_level=2'])

add_project_arguments(['-DWLR_USE_UNSTABLE'], language: ['cpp', 'c'])

wlroots        = dependency('wlroots', fallback: ['wlroots', 'wlroots'])
cairo          = dependency('cairo')
libinput       = dependency('libinput', version: '>=1.7.0')
pixman         = dependency('pixman-1')
threads        = dependency('threads')
xkbcommon      = dependency('xkbcommon')
wfconfig       = dependency('wf-config')

decoration = shared_module('decoration',
    ['decoration.cpp', 'deco-subsurface.cpp', 'deco-button.cpp',
      'deco-layout.cpp', 'deco-theme.cpp'],
    dependencies: [wlroots, pixman, wfconfig, cairo],
    install: true,
    install_dir: join_paths(get_option('libdir'), 'wayfire'))

install_subdir('resources', install_dir: 'share/wayfire/decoration')
