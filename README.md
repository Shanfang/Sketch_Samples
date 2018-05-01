# Introduction

This repo contains implementation of sketching algorithms for size of join estimation. The update performance of sketches can be significantly improved if only a sample of the data is sketched, without significant degradation in the accuracy. In this repo, Bernoulli sampling is used. For details of the sampling algorithms and sketching techniques, please checkout the references page.

## Prerequisite
### Install GSL
If you are using Mac, follow these steps:
1. launch the terminal
2. run <br/><nobr>`ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)" < /dev/null 2> /dev/null`</nobr>
3. run <br/>`brew install gsl`

For other systems, please checkout the documentation on [GSL](https://www.gnu.org/software/gsl/doc/html/index.html)
## How to run the code
1. run `make`
2. run `./sketch_bernoulli_sampling.out` followed by the following parameters: 
<br/>dom_size 
<br/>tuples_no
<br/>buckets_no
<br/>rows_no 
<br/>DIST_PARAM 
<br/>DIST_SHUFF 
<br/>SAMP_PROB 
<br/>num_runs
</br>For details of corresponding parameters, please checkout the documentation at [GitHub Wiki](https://github.com/Shanfang/Sketch_Samples/wiki)
3. run `make clean` to remove all intermediate files.
