{ pkgs ? import <nixpkgs> {} }:

with pkgs;
mkShell {
    nativeBuildInputs = [ gcc7 go ];

    shellHook = "exec dash"; # Feel free to remove
}
