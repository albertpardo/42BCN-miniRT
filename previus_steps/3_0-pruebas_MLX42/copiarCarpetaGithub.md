Ejemplo usando [https://github.com/pulgamecanica/42Course/tree/main/42Documentation/mlx42_intro](https://github.com/pulgamecanica/42Course/tree/main/42Documentation/mlx42_intro)

```sh
git init 42Course
cd 42Course
git remote add origin https://github.com/pulgamecanica/42Course.git
git config core.sparseCheckout true
echo "42Documentation/mlx42_intro/*" >> .git/info/sparse-checkout
```

El repositorio tiene la rama **main**

```sh
git pull --depth=1 origin main
```

Las carpetas que github las tiene redirecionadas a otro repositorio no las copia.
