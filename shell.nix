{ pkgs ? import <nixpkgs> {} }:

with pkgs;
mkShell {
    nativeBuildInputs = [
        gcc7 sourcekit-lsp
        go gopls
    ];

    shellHook = ''
        export CFLAGS="-lm -O2 -fno-stack-limit -std=c++1z -x c++"
        export GOFLAGS="-gccgoflags=-O2 -gccgoflags=-fno-stack-limit'"
        exec dash # Feel free to remove
    '';
}
