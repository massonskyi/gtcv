from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import pybind11

ext_modules = [
    Extension(
        'gtcv',
        ['lib/python_bindings/bindings.cpp'],
        include_dirs=[pybind11.get_include()],
        extra_compile_args=['-std=c++11'],
    ),
]

setup(
    name='OpenGTCV',
    version='0.1',
    author='massonsky',
    description='This library is a python wrapper for the gtcv library',
    long_description=open('README.md').read(),
    long_description_content_type='text/markdown',
    url='https://github.com/massonskyi/gtcv',
    classifiers=[
        'Programming Language :: Python :: 3',
        'License :: OSI Approved :: MIT License',
        'Operating System :: OS Independent',
    ],
    python_requires='>=3.6',
    ext_modules=ext_modules,
    cmdclass={'build_ext': build_ext},
    zip_safe=False,
    package_data={
        '': ['*.pyi'],
    },
    packages=['lib.python_bindings', 'OpenGTCV'],
)